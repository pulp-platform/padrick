from copy import deepcopy

from lark import Token
from lark.exceptions import UnexpectedInput
from lark.lark import Lark
from lark.tree import Tree
from lark.visitors import Transformer, v_args
from padrick.Model.TemplatedIndexGrammar import TemplatedIdxToStringTransformer, TemplatedIdxEvaluator, templated_index_grammar

grammar = r"""
?start: (idx_template | TEXT)*
TEXT: /[^{}]+/ 
"""

templated_string_parser = Lark(grammar + templated_index_grammar, parser='lalr')

class TemplatedStringType(str):
    _expression: str
    ast: Tree

    def __init__(self, expression: str):
        super().__init__()
        if expression == None:
            expression = ""
        self._ast = templated_string_parser.parse(str(expression))


    def __str__(self):
        if isinstance(self._ast, str):
            return self._ast
        else:
            return TemplatedIdxToStringTransformer().transform(self._ast)

    @property
    def identifier(self) -> str:
        return str(self)

    @property
    def ast(self):
        return self._ast

    def evaluate_template(self, i):
        copy = deepcopy(self)
        if not isinstance(self._ast, Token):
            copy._ast = (TemplatedIdxEvaluator(i) * TemplatedIdxToStringTransformer()).transform(self._ast)
        return copy

    @classmethod
    def __get_validators__(cls):
        yield cls.validate

    @classmethod
    def validate(cls, v):
        try:
            expr = cls(v)
        except UnexpectedInput as e:
            raise ValueError(f'Error while parsing expression: {v}.\nError {str(e)}')
        return expr

    def __repr__(self):
        return self.__str__()

if __name__ == "__main__":
    expr = TemplatedStringType.validate("This is a test <i+10> !!!")
    print(expr.evaluate_template(42))

from copy import deepcopy
from typing import Set, Mapping

from lark.exceptions import UnexpectedInput
from lark.lark import Lark
from lark.tree import Tree
from lark.visitors import Transformer

expression_language = r"""
?start: expression

?expression: _primary
          | UNARY_OP _primary -> unary_operation
          | "(" expression ")"
          | expression BINARY_OP expression -> binary_operation
          | empty_expression
          
empty_expression: WS*
          
_primary: literal
       | signal_expression

literal: integral_number

signal_expression: signal //("[" constant_range_expression "]")*

signal: CNAME -> signal_name

?constant_range_expression: constant_expression
                         | constant_part_select_range

?constant_part_select_range: constant_range
                          | constant_indexed_range
                          
constant_range: constant_expression ":" constant_expression

constant_indexed_range: constant_expression "+" ":" constant_expression
                      | constant_expression "-" ":" constant_expression

?constant_expression: constant_primary
                   | constant_expression BINARY_OP constant_expression
                   | UNARY_OP constant_expression
                   | constant_expression "?" constant_expression ":" constant_expression
                   
?constant_primary: integral_number
                   
?integral_number: decimal_number
               | octal_number
               | binary_number
               | hex_number

decimal_number: DECIMAL_VALUE
              | SIZE? DECIMAL_BASE DECIMAL_VALUE
DECIMAL_VALUE: /[0-9][_0-9]*/
octal_number: SIZE? OCTAL_BASE OCTAL_VALUE
OCTAL_VALUE: /[0-7][_0-7]*/
binary_number: SIZE? BINARY_BASE BINARY_VALUE
BINARY_VALUE: /[01][_01]*/
hex_number: SIZE? HEX_BASE HEX_VALUE
HEX_VALUE: /[0-9a-fA-F][_0-9a-fA-F]*/

UNSIGNED_NUMBER: /[0-9]+/
SIZE: /[1-9][_0-9]*/
DECIMAL_BASE: /'[s|S]?d|'[s|S]?D/
BINARY_BASE: /'[s|S]?b|'[s|S]?B/
OCTAL_BASE: /'[s|S]?o|'[s|S]?O/
HEX_BASE: /'[s|S]?h|'[s|S]?H/

UNARY_OP: /\+|-|!|~|&|~&|\||~|\^|~\^|\^~/

BINARY_OP: /\+|-|\*|\/|%|==|!=|===|!==|==?|!=\?|&&|\|\||\*\*|<|<=|>|>=|&|\||\^|\^~|~\^|>>|<<|>>>|<<<|->|<->/

%import common.CNAME
%import common.WS
%ignore WS
"""

simple_expression_parser = Lark(expression_language)

class ExprToStringTransformer(Transformer):
    def __default__(self, data, children, meta):
        return "".join(children)
    def __default_token__(self, token):
        return str(token)

class SignalNameRemapTransformer(Transformer):
    def __init__(self, signal_name_mapping: Mapping[str, str]):
        super().__init__()
        self._map = signal_name_mapping

    def CNAME(self, name):
        return self._map.get(name, name)


class SignalExpressionType:
    _expression: str
    ast: Tree

    def __init__(self, expression: str):
        if expression == None:
            expression = ""
        self._ast = simple_expression_parser.parse(str(expression))


    def __str__(self):
        return ExprToStringTransformer().transform(self._ast)

    def get_mapped_expr(self, signal_name_mapping: Mapping[str, str]) -> 'SignalExpressionType':
        clone = deepcopy(self)
        clone._ast = SignalNameRemapTransformer(signal_name_mapping).transform(clone._ast)
        return clone

    @property
    def expression(self) -> str:
        return str(self)

    @property
    def ast(self):
        return self._ast

    @property
    def is_empty(self):
        return str(self) == ""

    @property
    def is_const_expr(self):
        return len(self.signal_collection) == 0

    @property
    def is_single_signal(self):
        return self.ast.data == "signal_expression"

    @property
    def signal_collection(self):
        signal_collection = set()
        for signal_name in self.ast.find_data('signal_name'):
            signal_collection.add(signal_name.children[0])
        return signal_collection

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
        return self.expression

if __name__ == "__main__":
    expr = SignalExpressionType.validate("clk_i+1")
    print(expr.expression)
    print(expr.signal_collection)
    print(expr.is_const_expr)
    print(expr.is_single_signal)
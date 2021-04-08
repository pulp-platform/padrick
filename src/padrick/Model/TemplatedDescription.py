from copy import deepcopy

from lark.exceptions import UnexpectedInput
from lark.lark import Lark
from lark.tree import Tree
from lark.visitors import Transformer, v_args

expression_language = r"""
?start: identifier

identifier: (UNDERSCORE|LETTER) (UNDERSCORE|LETTER|DIGIT|idx_template)*
idx_template: "<" idx_expression ">"
?idx_expression: term (TERM_OP idx_expression)?
?term: factor (FACTOR_OP term)?
?factor: constant | INDEX_VAR | "(" idx_expression ")"
constant: INT
INDEX_VAR: "i"
FACTOR_OP: "*" | "/" | "%"
TERM_OP: "+" | "-"
UNDERSCORE: "_"

// It would be cleaner to import those rules from Lark common grammar but this prevents pyoxidized binary creation 
// due to stupid package resource importing scheme used in lark
// Basic terminals for common use


//
// Numbers
//

DIGIT: "0".."9"
HEXDIGIT: "a".."f"|"A".."F"|DIGIT

INT: DIGIT+
SIGNED_INT: ["+"|"-"] INT
DECIMAL: INT "." INT? | "." INT

// float = /-?\d+(\.\d+)?([eE][+-]?\d+)?/
_EXP: ("e"|"E") SIGNED_INT
FLOAT: INT _EXP | DECIMAL _EXP?
SIGNED_FLOAT: ["+"|"-"] FLOAT

NUMBER: FLOAT | INT
SIGNED_NUMBER: ["+"|"-"] NUMBER

//
// Strings
//
_STRING_INNER: /.*?/
_STRING_ESC_INNER: _STRING_INNER /(?<!\\)(\\\\)*?/

ESCAPED_STRING : "\"" _STRING_ESC_INNER "\""


//
// Names (Variables)
//
LCASE_LETTER: "a".."z"
UCASE_LETTER: "A".."Z"

LETTER: UCASE_LETTER | LCASE_LETTER
WORD: LETTER+

CNAME: ("_"|LETTER) ("_"|LETTER|DIGIT)*

//
// Whitespace
//
WS_INLINE: (" "|/\t/)+
WS: /[ \t\f\r\n]/+

CR : /\r/
LF : /\n/
NEWLINE: (CR? LF)+


// Comments
SH_COMMENT: /#[^\n]*/
CPP_COMMENT: /\/\/[^\n]*/
C_COMMENT: "/*" /(.|\n)*?/ "*/"
SQL_COMMENT: /--[^\n]*/

%ignore WS
"""

templated_identifier_parser = Lark(expression_language)


class ExprToStringTransformer(Transformer):
    def __default__(self, data, children, meta):
        return "".join(children)
    def __default_token__(self, token):
        return str(token)

    def id_template(self, children):
        return "<" + "".join(children) + ">"

@v_args(inline=True)
class TemplatedIndexEvaluator(Transformer):
    def __init__(self, i: int):
        super().__init__()
        self.i = i

    def constant(self, token):
        return int(token)

    def INDEX_VAR(self, token):
        return self.i

    def term(self, left, operator, right):
        if (operator == "*"):
            return left * right
        elif(operator == "/"):
            return left / right
        elif(operator == "%"):
            return  left % right
        else:
            raise ValueError(f"Unknown operator {operator}")

    def id_expression(self, left, operator, right):
        if (operator == "+"):
            return left + right
        elif (operator == "-"):
            return left - right
        else:
            raise ValueError(f"Unknown operator {operator}")

    def id_template(self, value):
        return str(value)

class TemplatedIdentifierType(str):
    _expression: str
    ast: Tree

    def __init__(self, expression: str):
        super().__init__()
        if expression == None:
            expression = ""
        self._ast = templated_identifier_parser.parse(str(expression))


    def __str__(self):
        return ExprToStringTransformer().transform(self._ast)

    @property
    def identifier(self) -> str:
        return str(self)

    @property
    def ast(self):
        return self._ast

    def evaluate_template(self, i):
        return (TemplatedIndexEvaluator(i) * ExprToStringTransformer()).transform(self._ast)

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
    expr = TemplatedIdentifierType.validate("test_<>")
    print(expr.evaluate_template(42))

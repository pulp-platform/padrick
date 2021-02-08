from typing import Set

from lark.exceptions import UnexpectedInput
from lark.lark import Lark
from lark.tree import Tree

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

class SignalExpressionType:
    _is_literal: bool
    _signal_collection: Set[str]
    _expression: str
    _is_empty: bool = False
    ast: Tree

    def __init__(self, expression: str):
        if expression == None:
            expression = ""
            self._is_empty = True
        self._ast = simple_expression_parser.parse(str(expression))
        self._expression = str(expression)
        self._signal_collection = set()
        for signal_name in self.ast.find_data('signal_name'):
            self._signal_collection.add(signal_name.children[0].value)

    @property
    def expression(self):
        return self._expression

    @property
    def ast(self):
        return self._ast
    @property
    def is_empty(self):
        return self._is_empty

    @property
    def is_const_expr(self):
        return len(self._signal_collection) == 0

    @property
    def signal_collection(self):
        return self._signal_collection

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
    expr = SignalExpressionType.validate("45*44+clk_i")
    print(expr.expression)
    print(expr.signal_collection)
    print(expr.is_const_expr)
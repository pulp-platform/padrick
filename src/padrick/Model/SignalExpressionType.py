from copy import deepcopy
from typing import Set, Mapping

from lark.exceptions import UnexpectedInput
from lark.lark import Lark
from lark.tree import Tree
from lark.visitors import Transformer

from padrick.Model.TemplatedIndexGrammar import templated_index_grammar, TemplatedIdxEvaluator, \
    TemplatedIdxToStringTransformer

expression_language = r"""
?start: expression

?expression: _primary
          | UNARY_OP WS? _primary -> unary_operation
          | "(" WS? expression WS? ")"
          | expression WS? BINARY_OP WS? expression -> binary_operation
          | empty_expression
          
empty_expression: WS*
          
_primary: literal
       | signal_expression

literal: integral_number

signal_expression: signal //("[" constant_range_expression "]")*

signal: (UNDERSCORE|LETTER) (UNDERSCORE|LETTER|DIGIT|idx_template)* -> signal_name

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
               | SHORTCUT_VECTOR
               
SHORTCUT_VECTOR: /'[01]/

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

//%ignore WS
"""

simple_expression_parser = Lark(expression_language+templated_index_grammar, parser="earley")

class SignalNameRemapTransformer(Transformer):
    def __init__(self, signal_name_mapping: Mapping[str, str]):
        super().__init__()
        self._map = signal_name_mapping

    def signal_name(self, characters):
        name = "".join(characters)
        return self._map.get(name, name)



class SignalExpressionType(str):
    _expression: str
    ast: Tree

    def __init__(self, expression: str):
        super().__init__()
        if expression == None:
            self._ast = ""
        elif isinstance(expression, str):
            try:
                self._ast = simple_expression_parser.parse(expression)
            except UnexpectedInput as e:
                raise ValueError("Illegal signal expresion: "+str(e))
        else:
            raise ValueError("Expression must be a string or None")

    def get_mapped_expr(self, signal_name_mapping: Mapping[str, str]) -> 'SignalExpressionType':
        return (SignalNameRemapTransformer(signal_name_mapping)*TemplatedIdxToStringTransformer()).transform(self.ast)

    def evaluate_template(self, i):
        if not isinstance(self.ast, str):
            return SignalExpressionType((TemplatedIdxEvaluator(i)*TemplatedIdxToStringTransformer()).transform(self.ast))
        else:
            return self

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
            signal_collection.add(TemplatedIdxToStringTransformer().transform(signal_name))
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
    expr = SignalExpressionType.validate("1'b0")
    print(expr.expression)
    print(expr.signal_collection)
    print(expr.is_const_expr)
    print(expr.is_single_signal)
    evaluated_expr = expr.evaluate_template(41)
    print(evaluated_expr)
    mapped_expr = evaluated_expr.get_mapped_expr({'clk41_i':'test_o'})
    print(mapped_expr)

from typing import List

from lark import Transformer, v_args, Tree

templated_index_grammar = r"""
idx_template: "{" idx_expression format_spec? "}"
?idx_expression: term (TERM_OP idx_expression)?
?term: factor (FACTOR_OP term)?
?factor: constant | INDEX_VAR | "(" idx_expression ")"
format_spec: ":" length? format_class
length: constant 
constant: /[0-9]+/
!format_class: "d"|"c"|"C"
INDEX_VAR: "i"
FACTOR_OP: "*" | "/" | "%"
TERM_OP: "+" | "-"
UNDERSCORE: "_"
"""

class TemplatedIdxToStringTransformer(Transformer):
    def __default__(self, data, children, meta):
        return "".join(children)
    def __default_token__(self, token):
        return str(token)

    def idx_template(self, children):
        return "{" + "".join(children) + "}"

@v_args(inline=True)
class TemplatedIdxEvaluator(Transformer):
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

    def idx_expression(self, left, operator, right):
        if (operator == "+"):
            return left + right
        elif (operator == "-"):
            return left - right
        else:
            raise ValueError(f"Unknown operator {operator}")

    def number_to_base26(cls, value:int) -> List[int]:
        if value<0:
            raise ValueError("Value must not be negative.")
        result = []
        while value:
            value, digit = divmod(value, 26)
            result.insert(0, digit)
        return result

    def idx_template(self, idx_expression, format_spec: Tree):
        if format_spec:
            length = next(format_spec.find_data('length'), None)
            if length is None:
                length = 0
            else:
                length = length.children[0]
            format_class = next(format_spec.find_data('format_class')).children[0]
            if format_class in ['d', 'o', 'b', 'X']:
                return '{idx_expression:0{length}{format_class}}'.format(idx_expression=idx_expression,
                                                                         length=length, format_class=format_class)
            elif format_class in ['c', 'C']:
                base26_value = self.number_to_base26(idx_expression)
                if len(base26_value) < length:
                    base26_value = (length - len(base26_value))*[0]+base26_value
                if format_class == 'c':
                    start_character = 'a'
                else:
                    start_character = 'A'
                return "".join(map(lambda x: chr(ord(start_character)+x), base26_value))
        else:
            return str(idx_expression)


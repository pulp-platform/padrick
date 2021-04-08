from lark import Transformer, v_args

templated_index_grammar = r"""
idx_template: "<" idx_expression ">"
?idx_expression: term (TERM_OP idx_expression)?
?term: factor (FACTOR_OP term)?
?factor: constant | INDEX_VAR | "(" idx_expression ")"
constant: /[0-9]+/
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
        return "<" + "".join(children) + ">"

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

    def idx_template(self, value):
        return str(value)


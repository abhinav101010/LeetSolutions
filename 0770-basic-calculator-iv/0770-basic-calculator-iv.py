from typing import List, Dict, Tuple
import re
import itertools

class Polynomial:
    def __init__(self, terms: Dict[Tuple[str, ...], int] = None):
        self.terms = terms if terms is not None else {}
        self._normalize()
    
    def _normalize(self):
        # remove zero coefficients
        self.terms = {k: v for k, v in self.terms.items() if v != 0}
    
    def __add__(self, other):
        res = Polynomial()
        for k, v in self.terms.items():
            res.terms[k] = res.terms.get(k, 0) + v
        for k, v in other.terms.items():
            res.terms[k] = res.terms.get(k, 0) + v
        res._normalize()
        return res
    
    def __sub__(self, other):
        res = Polynomial()
        for k, v in self.terms.items():
            res.terms[k] = res.terms.get(k, 0) + v
        for k, v in other.terms.items():
            res.terms[k] = res.terms.get(k, 0) - v
        res._normalize()
        return res
    
    def __mul__(self, other):
        res = Polynomial()
        for k1, v1 in self.terms.items():
            for k2, v2 in other.terms.items():
                # multiply variables: combine and sort
                vars = tuple(sorted(k1 + k2))
                res.terms[vars] = res.terms.get(vars, 0) + v1 * v2
        res._normalize()
        return res
    
    def constant(self, val: int):
        self.terms[()] = self.terms.get((), 0) + val
        self._normalize()
        return self
    
    def variable(self, var: str):
        self.terms[(var,)] = self.terms.get((var,), 0) + 1
        self._normalize()
        return self
    
    def to_list(self) -> List[str]:
        # sort by degree descending, then lexicographically
        items = []
        for vars, coeff in self.terms.items():
            if coeff == 0:
                continue
            if not vars:
                term = str(coeff)
            else:
                var_str = '*'.join(vars)
                term = f"{coeff}*{var_str}" if abs(coeff) != 1 else (f"{var_str}" if coeff == 1 else f"-{var_str}")
                # Actually we need coefficient included always? LeetCode expects coefficient * variables, coefficient can be 1 or -1 omitted? 
                # According to examples, they output like "-2*a*a*b" etc. They include coefficient even if 1? 
                # Example: "e + 8 - a + 5" with e=1 => "14" and "-1*a". They show coefficient 1.
                # So we always include coefficient.
                term = f"{coeff}*{var_str}"
            items.append((len(vars), vars, coeff, term))
        # sort: first by degree descending, then by vars lexicographically
        items.sort(key=lambda x: (-x[0], x[1]))
        return [term for _, _, _, term in items]

class Solution:
    def basicCalculatorIV(self, expression: str, evalvars: List[int], evalints: List[int]) -> List[str]:
        eval_map = {v: i for v, i in zip(evalvars, evalints)}
        # tokenize
        tokens = re.findall(r'\d+|[a-z]+|[+\-*/()]', expression)
        # we'll use two stacks: values and ops
        values = []
        ops = []
        def apply_op():
            op = ops.pop()
            b = values.pop()
            a = values.pop()
            if op == '+':
                values.append(a + b)
            elif op == '-':
                values.append(a - b)
            elif op == '*':
                values.append(a * b)
            elif op == '/':
                # integer division truncate toward zero?
                # In Basic Calculator IV, division is integer division? Actually there is no division in the problem? 
                # Looking at Basic Calculator IV, only + - * and parentheses, no division.
                # So we can ignore.
                pass
        precedence = {'+':1, '-':1, '*':2}
        for token in tokens:
            if token.isdigit():
                values.append(Polynomial().constant(int(token)))
            elif token.isalpha():
                if token in eval_map:
                    values.append(Polynomial().constant(eval_map[token]))
                else:
                    values.append(Polynomial().variable(token))
            elif token == '(':
                ops.append(token)
            elif token == ')':
                while ops and ops[-1] != '(':
                    apply_op()
                ops.pop()  # remove '('
            else:  # operator
                while ops and ops[-1] != '(' and precedence[ops[-1]] >= precedence[token]:
                    apply_op()
                ops.append(token)
        while ops:
            apply_op()
        return values[-1].to_list() if values else []

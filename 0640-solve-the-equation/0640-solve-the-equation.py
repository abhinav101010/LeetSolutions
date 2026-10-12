import re

class Solution:
    def solveEquation(self, equation: str) -> str:
        left, right = equation.split('=')
        
        def count(exp):
            coeff = 0
            const = 0
            tokens = re.findall(r'([+-]?\d*)([xX]?)', exp)
            for num_str, var in tokens:
                if var:
                    if num_str in ('', '+'):
                        coeff += 1
                    elif num_str == '-':
                        coeff -= 1
                    else:
                        coeff += int(num_str)
                else:
                    if num_str:
                        const += int(num_str)
            return coeff, const
        
        coeff_l, const_l = count(left)
        coeff_r, const_r = count(right)
        
        coeff = coeff_l - coeff_r
        const = const_r - const_l
        
        if coeff == 0 and const == 0:
            return "Infinite solutions"
        if coeff == 0 and const != 0:
            return "No solution"
        x = const // coeff
        return f"x={x}"
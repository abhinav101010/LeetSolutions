class Solution:
    def calculate(self, s: str) -> int:
        def apply_op(operands, operators):
            b = operands.pop()
            a = operands.pop()
            op = operators.pop()
            if op == '+':
                operands.append(a + b)
            elif op == '-':
                operands.append(a - b)
            elif op == '*':
                operands.append(a * b)
            elif op == '/':
                # truncate toward zero
                if a * b < 0:
                    operands.append(-(abs(a) // abs(b)))
                else:
                    operands.append(a // b)
        
        precedence = {'+':1, '-':1, '*':2, '/':2}
        operands = []
        operators = []
        i = 0
        n = len(s)
        while i < n:
            ch = s[i]
            if ch == ' ':
                i += 1
                continue
            if ch.isdigit():
                num = 0
                while i < n and s[i].isdigit():
                    num = num * 10 + int(s[i])
                    i += 1
                operands.append(num)
                continue
            if ch == '(':
                operators.append(ch)
            elif ch == ')':
                while operators and operators[-1] != '(':
                    apply_op(operands, operators)
                operators.pop()  # remove '('
            else:  # operator
                while operators and operators[-1] != '(' and precedence[operators[-1]] >= precedence[ch]:
                    apply_op(operands, operators)
                operators.append(ch)
            i += 1
        while operators:
            apply_op(operands, operators)
        return operands[-1] if operands else 0

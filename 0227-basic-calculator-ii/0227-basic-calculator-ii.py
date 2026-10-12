class Solution:
    def calculate(self, s: str) -> int:
        num = 0
        sign = '+'
        stack = []
        
        for i, c in enumerate(s):
            if c.isdigit():
                num = num * 10 + int(c)
            
            if c in '+-*/' or i == len(s) - 1:
                if sign == '+':
                    stack.append(num)
                elif sign == '-':
                    stack.append(-num)
                elif sign == '*':
                    stack.append(stack.pop() * num)
                elif sign == '/':
                    prev = stack.pop()
                    if prev < 0:
                        stack.append(-(-prev // num))
                    else:
                        stack.append(prev // num)
                sign = c
                num = 0
        
        return sum(stack)
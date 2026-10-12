class Solution:
    def calculate(self, s: str) -> int:
        num = 0
        sign = 1
        result = 0
        stack = []
        
        for c in s:
            if c.isdigit():
                num = num * 10 + int(c)
            elif c == '+':
                result += sign * num
                num = 0
                sign = 1
            elif c == '-':
                result += sign * num
                num = 0
                sign = -1
            elif c == '(':
                stack.append(result)
                stack.append(sign)
                result = 0
                sign = 1
            elif c == ')':
                result += sign * num
                num = 0
                result *= stack.pop()  # sign
                result += stack.pop()  # previous result
        
        return result + sign * num
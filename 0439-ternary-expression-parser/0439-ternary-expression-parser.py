class Solution:
    def parseTernary(self, expression: str) -> str:
        stack = []
        n = len(expression)
        for i in range(n - 1, -1, -1):
            if expression[i] == '?':
                true_char = stack.pop()
                stack.pop()  # ':'
                false_char = stack.pop()
                if expression[i - 1] == 'T':
                    stack.append(true_char)
                else:
                    stack.append(false_char)
                i -= 1
            elif expression[i] != ':':
                stack.append(expression[i])
        return stack[0]

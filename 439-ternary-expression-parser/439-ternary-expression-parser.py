class Solution:
    def parseTernary(self, expression: str) -> str:
        stack = []
        i = len(expression) - 1
        while i >= 0:
            ch = expression[i]
            if stack and stack[-1] == '?':
                # pop '?'
                stack.pop()
                # pop true-value
                true_val = stack.pop()
                # pop false-value
                false_val = stack.pop()
                # pop condition (T or F)
                condition = stack.pop()
                if condition == 'T':
                    stack.append(true_val)
                else:
                    stack.append(false_val)
                i -= 1  # skip the condition (already popped)
            else:
                stack.append(ch)
            i -= 1
        return stack[-1]

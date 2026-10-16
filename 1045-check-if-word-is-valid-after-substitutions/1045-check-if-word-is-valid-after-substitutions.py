class Solution:
    def isValid(self, S):
        stack = []
        for c in S:
            if c == 'c':
                if len(stack) < 2 or stack[-1] != 'b' or stack[-2] != 'a':
                    return False
                stack.pop()
                stack.pop()
            else:
                stack.append(c)
        return len(stack) == 0

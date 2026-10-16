class Solution:
    def clumsy(self, N):
        ops = ['*', '//', '+', '-']
        stack = [N]
        op = 1
        for i in range(N-1, 0, -1):
            if ops[(op-1)%4] == '*':
                stack[-1] *= i
            elif ops[(op-1)%4] == '//':
                stack[-1] = int(stack[-1] // i)
            elif ops[(op-1)%4] == '+':
                stack.append(i)
            else:
                stack.append(-i)
            op += 1
        return sum(stack)

class Solution:
    def maxWidthRamp(self, A: list[int]) -> int:
        n = len(A)
        stack = []
        for i in range(n):
            if not stack or A[i] < A[stack[-1]]:
                stack.append(i)
        ans = 0
        for j in range(n-1, -1, -1):
            while stack and A[stack[-1]] <= A[j]:
                ans = max(ans, j - stack.pop())
        return ans

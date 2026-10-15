class Solution:
    def minIncrementForUnique(self, A: list[int]) -> int:
        if not A:
            return 0
        A.sort()
        ans = 0
        prev = A[0]
        for i in range(1, len(A)):
            if A[i] <= prev:
                ans += prev + 1 - A[i]
                prev = prev + 1
            else:
                prev = A[i]
        return ans

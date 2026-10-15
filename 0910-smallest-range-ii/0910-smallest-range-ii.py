class Solution:
    def smallestRangeII(self, A: list[int], K: int) -> int:
        A.sort()
        n = len(A)
        ans = A[n-1] - A[0]  # without any change (or adding same K to all)
        for i in range(n-1):
            high = max(A[i] + K, A[n-1] - K)
            low = min(A[0] + K, A[i+1] - K)
            ans = min(ans, high - low)
        return ans

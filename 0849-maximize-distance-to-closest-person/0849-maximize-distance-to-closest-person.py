class Solution:
    def maxDistToClosest(self, seats: list[int]) -> int:
        n = len(seats)
        left = [n] * n
        right = [n] * n
        for i in range(n):
            if seats[i] == 1:
                left[i] = 0
            elif i > 0:
                left[i] = left[i-1] + 1
        for i in range(n-1, -1, -1):
            if seats[i] == 1:
                right[i] = 0
            elif i < n-1:
                right[i] = right[i+1] + 1
        ans = 0
        for i in range(n):
            ans = max(ans, min(left[i], right[i]))
        return ans

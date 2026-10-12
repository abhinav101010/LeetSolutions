class Solution:
    def maxWidthOfVerticalArea(self, points):
        x = sorted(point[0] for point in points)

        ans = 0

        for i in range(1, len(x)):
            ans = max(ans, x[i] - x[i - 1])

        return ans
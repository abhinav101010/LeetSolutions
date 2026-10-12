class Solution:
    def trap(self, height: List[int]) -> int:
        # ans = 0

        # for i in range(len(height)):
        #     for j in range(i + 1, len(height)):
        #         if j - i <= 1:
        #             continue

        #         waterLevel = min(height[i], height[j])

        #         for k in range(i + 1, j):
        #             if waterLevel > height[k]:
        #                 ans += waterLevel - height[k]

        # return ans

        ans = 0

        maxL = height[0]
        maxR = height[-1]

        left = 0
        right = len(height)-1

        while left < right:
            if maxL <= maxR:
                left += 1
                maxL = max(maxL, height[left])
                ans += max(0, maxL - height[left])
            else:
                right -= 1
                maxR = max(maxR, height[right])
                ans += max(0, maxR - height[right])

        return ans
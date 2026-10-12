class Solution:
    def maxProduct(self, nums: List[int]) -> int:
# Gives TLE
        # n = len(nums)
        # ans = nums[0]

        # for i in range(n):
        #     product = 1
        #     for j in range(i, n):
        #         product *= nums[j]
        #         ans = max(ans, product)

        # return ans

        highest = nums[0]
        least = nums[0]
        ans = nums[0]

        for i in range(1, len(nums)):
            num = nums[i]

            if num < 0:
                highest, least = least, highest

            highest = max(num, highest * num)
            least = min(num, least * num)

            ans = max(ans, highest)

        return ans
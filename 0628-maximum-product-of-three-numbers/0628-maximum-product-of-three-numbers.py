class Solution:
    def maximumProduct(self, nums: List[int]) -> int:
        # ans = nums[0] * nums[1] * nums[2]

        # for i in range(len(nums)):
        #     for j in range(i + 1, len(nums)):
        #         for k in range(j + 1, len(nums)):
        #             ans = max(ans, nums[i] * nums[j] * nums[k])
        # return ans


        first = max(nums)
        # nums.remove(first)
        # second = max(nums)
        # nums.remove(second)
        # third = max(nums)

        # ans = first*second*third

        # firstMin = min(nums)
        # nums.remove(firstMin)
        # secondMin = min(nums)
        # return max(ans, first*firstMin*secondMin)

        nums.sort()

        return max(
            nums[-1] * nums[-2] * nums[-3],
            nums[0] * nums[1] * nums[-1]
        )


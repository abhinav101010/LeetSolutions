class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        if not nums: return 0
        nums.sort()
        ans = 1
        length = 1

        for i in range(len(nums) - 1):
            if nums[i + 1] == nums[i]:
                continue
            elif nums[i + 1] - nums[i] == 1:
                length += 1
            else:
                ans = max(ans, length)
                length = 1

        ans = max(ans, length)
        return ans
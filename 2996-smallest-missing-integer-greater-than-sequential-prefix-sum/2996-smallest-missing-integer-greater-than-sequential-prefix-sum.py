class Solution:
    def missingInteger(self, nums: List[int]) -> int:
        total = nums[0]

        for i in range(1, len(nums)):
            if nums[i] == nums[i - 1] + 1:
                total += nums[i]
            else:
                break

        numsSet = set(nums)

        while total in numsSet:
            total += 1

        return total
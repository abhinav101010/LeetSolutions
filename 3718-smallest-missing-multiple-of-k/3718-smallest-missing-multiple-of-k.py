class Solution:
    def missingMultiple(self, nums: List[int], k: int) -> int:
        numsSet = set(nums)

        multiple = k

        while multiple in numsSet:
            multiple += k

        return multiple
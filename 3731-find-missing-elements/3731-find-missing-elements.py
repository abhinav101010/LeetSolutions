class Solution:
    def findMissingElements(self, nums: List[int]) -> List[int]:
        if not nums: return []
        nums.sort()
        numsSet = set(nums)

        ans = []

        for i in range(nums[0], nums[-1] + 1):
            if i not in numsSet:
                ans.append(i)

        return ans
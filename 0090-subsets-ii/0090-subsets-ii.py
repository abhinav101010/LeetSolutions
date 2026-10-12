class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        ans = set()
        def subsets(nums, i, curr):
            if len(nums) == i:
                ans.add(tuple(sorted(curr)))
                return

            subsets(nums, i+1, curr)
            subsets(nums, i+1, curr+[nums[i]])
        subsets(nums, 0, [])
        return list(ans)
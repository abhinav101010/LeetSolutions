class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        ans = []
        def sub(nums, i, curr):
            nonlocal ans
            if len(nums) == i:
                ans.append(curr)
                return
            
            sub(nums, i+1, curr)
            sub(nums, i+1, curr+[nums[i]])
        sub(nums, 0, [])
        return ans
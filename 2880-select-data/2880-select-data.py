class Solution:
    def selectData(self, nums, target):
        res = []
        for i, v in enumerate(nums):
            if v == target:
                res.append(i)
        return res

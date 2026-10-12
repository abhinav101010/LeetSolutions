class Solution:
    def separateDigits(self, nums: List[int]) -> List[int]:
        ans = []
        for i in range(len(nums)):
            res = []
            while nums[i] > 0:
                res.append(nums[i]%10)
                nums[i] = nums[i]//10
            ans.extend(res[::-1])
        return ans
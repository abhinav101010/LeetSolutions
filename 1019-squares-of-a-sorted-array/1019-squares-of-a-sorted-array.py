class Solution:
    def sortedSquares(self, nums):
        left, right = 0, len(nums)-1
        res = []
        while left <= right:
            if abs(nums[left]) > abs(nums[right]):
                res.append(nums[left]*nums[left])
                left += 1
            else:
                res.append(nums[right]*nums[right])
                right -= 1
        return res[::-1]

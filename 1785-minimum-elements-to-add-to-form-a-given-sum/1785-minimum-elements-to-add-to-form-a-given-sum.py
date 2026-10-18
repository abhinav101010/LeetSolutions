class Solution:
    def minElements(self, nums, limit, goal) :
        d = abs(sum(nums) - goal)
        return (d + limit - 1) // limit

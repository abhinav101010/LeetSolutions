class Solution:
    def check(self, nums: List[int]) -> bool:
        joinedNums = nums + nums
        nums.sort()

        n=len(nums)
        for i in range(n):
            if joinedNums[i:i+n] == nums:
                return True
        return False
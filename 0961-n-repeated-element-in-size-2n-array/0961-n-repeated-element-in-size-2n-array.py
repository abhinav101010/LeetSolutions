class Solution:
    def repeatedNTimes(self, nums: List[int]) -> int:
        s = set()
        for i in range(len(nums)):
            s.add(nums[i])
            if(len(s) != i+1):
                return nums[i]
        return 0
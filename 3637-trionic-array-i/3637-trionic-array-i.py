class Solution:
    def isTrionic(self, nums: List[int]) -> bool:
        start = False
        mid = False
        end = False
        # if nums[0]>nums[1]: return False
        
        i = 1
        while i<len(nums) and nums[i]>nums[i-1]:
            i+=1
            start = True
            if i == len(nums): return False
        print(i)

        while i<len(nums) and nums[i]<nums[i-1] and start:
            i+=1
            mid = True
            if i == len(nums): return False
        print(i)

        while i<len(nums) and nums[i]>nums[i-1] and mid:
            i+=1
            end = True
        print(i)

        return True if start and mid and end and i == len(nums) else False







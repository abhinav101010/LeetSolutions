class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        # left = 0
        # right = len(nums)-1
        # toBeRemoved = []
        # while left<=right:
        #     if left>0 and nums[left-1] == nums[left]:
        #         toBeRemoved.append(left)
        #     if nums[left] == nums[left+1]:
        #         left+=2
        #         continue

        #     if right<len(nums)-1 and nums[right+1] == nums[right]:
        #         toBeRemoved.append(right)
        #     if nums[right] == nums[right-1]:
        #         right-=2
        #         continue
            
        #     left+=1
        #     right-=1

        # for i in sorted(toBeRemoved)[::-1]:
        #     nums.pop(i)
        # return len(nums)


        i = 0
        prev = nums[0]
        o = 1
        toBeR = []
        while i < len(nums):
            if i > 0 and nums[i] == prev:
                o+=1
            
            if i > 0 and nums[i] == prev and o > 2:
                toBeR.append(i)

            if i > 0 and nums[i] != prev:
                prev = nums[i]
                o = 1

            i+=1

        for i in sorted(toBeR)[::-1]:
            nums.pop(i)
        return len(nums)
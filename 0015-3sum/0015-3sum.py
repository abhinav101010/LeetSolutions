class Solution:
    def threeSum(self, nums: list[int]) -> list[list[int]]:
        nums.sort()
        ans = set()
        # for i in range(len(nums)):
        #     for j in range(i+1,len(nums)):
        #         for k in range(j+1,len(nums)):

        #             s = nums[i]+nums[j]+nums[k]
        #             if s == 0:
        #                 ans.add(tuple(sorted([nums[i],nums[j],nums[k]])))

        for i in range(len(nums)):
            left = i + 1
            right = len(nums)-1

            while left < right:
                s = nums[i]+nums[left]+nums[right]
                if s == 0:
                    ans.add(tuple(sorted([nums[i],nums[left],nums[right]])))
                    left+=1
                    right-=1
                elif s < 0:
                    left+=1
                    while left < right and nums[left] == nums[left - 1]:
                        left += 1
                elif s > 0:
                    right-=1
                    while left < right and nums[right] == nums[right + 1]:
                        right -= 1

        return list(ans)
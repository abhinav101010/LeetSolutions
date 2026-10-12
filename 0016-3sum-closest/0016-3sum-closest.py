# class Solution:
#     def threeSumClosest(self, nums: List[int], target: int) -> int:
#         ans = nums[0]+nums[1]+nums[2]
#         for i in range(0,len(nums)):
#             for j in range(i+1,len(nums)):
#                 for k in range(j+1,len(nums)):
#                     s = nums[i]+nums[j]+nums[k]
#                     if abs(s-target) < abs(ans-target):
#                         ans = s
#                     if abs(s-target) == 0: return s
#         return ans
        

class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()
        closest = nums[0] + nums[1] + nums[2]

        for i in range(len(nums) - 2):
            left = i + 1
            right = len(nums) - 1

            while left < right:
                curr = nums[i] + nums[left] + nums[right]

                if abs(curr - target) < abs(closest - target):
                    closest = curr

                if curr < target:
                    left += 1
                elif curr > target:
                    right -= 1
                else:
                    return curr

        return closest
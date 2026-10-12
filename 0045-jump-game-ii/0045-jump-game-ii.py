class Solution:
    def jump(self, nums: List[int]) -> int:
        # ans = 2**31

        # def take_step(nums: List[int], at: int, steps: int):
        #     nonlocal ans
        #     if len(nums)-1 <= at:
        #         ans = min(ans, steps)
        #         return

        #     for jump in range(1, min(nums[at], len(nums) - 1 - at) + 1):
        #         take_step(nums, at + jump, steps + 1)

        # take_step(nums, 0, 0)
        
        # return ans

        ans = 0
        l = r = 0

        while r < len(nums) - 1:
            farthest = 0
            for i in range(l,r+1):
                farthest = max(farthest, i+nums[i])
            
            l = r + 1
            r = farthest
            ans+=1
        return ans




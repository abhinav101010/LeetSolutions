class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
# Gives TLE
        # for i in range(len(nums)):
        #     for j in range(i+1, len(nums)):
        #         if nums[i] == nums[j] and abs(i - j) <= k:
        #             return True
        # return False
            
# Self implemented logic
        seen = {}
        for i in range(len(nums)):
            if nums[i] in seen:
                if abs(i - seen[nums[i]]) <= k:
                    return True
            seen[nums[i]] = i
        return False
        
class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        seen = {}
        ans = []

        for num in nums:
            if num in seen:
                seen[num] += 1
            else:
                seen[num] = 1

        for num in seen:
            if seen[num] > len(nums) // 3:
                ans.append(num)

        return ans
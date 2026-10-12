class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        counts = {}

        for num in nums:
            if num in counts:
                counts[num] += 1
            else:
                counts[num] = 1
        print(counts)

        ans = 0
        highestValue = 0
        for key,value in counts.items():
            if value > highestValue:
                highestValue = value
                ans = key
        return ans
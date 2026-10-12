class Solution:
    def findLucky(self, arr):
        freq = {}

        for num in arr:
            freq[num] = freq.get(num, 0) + 1

        ans = -1

        for num, count in freq.items():
            if num == count:
                ans = max(ans, num)

        return ans
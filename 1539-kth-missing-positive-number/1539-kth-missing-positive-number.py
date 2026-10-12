class Solution:
    def findKthPositive(self, arr, k):
        missing = 0
        num = 1

        while missing < k:
            if num not in arr:
                missing += 1
            if missing == k:
                return num
            num += 1
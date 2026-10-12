class Solution:
    def containsPattern(self, arr, m, k):
        for i in range(len(arr) - m * k + 1):
            pattern = arr[i:i + m]

            if arr[i:i + m * k] == pattern * k:
                return True

        return False
class Solution:
    def trimMean(self, arr):
        arr.sort()

        n = len(arr)
        remove = n // 20

        arr = arr[remove:n - remove]

        return sum(arr) / len(arr)
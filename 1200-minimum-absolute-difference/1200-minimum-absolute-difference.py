class Solution:
    def minimumAbsDifference(self, arr: List[int]) -> List[List[int]]:
        arr.sort()

        minDiff = float('inf')

        # Find minimum difference
        for i in range(1, len(arr)):
            minDiff = min(minDiff, arr[i] - arr[i - 1])

        ans = []

        # Find all pairs with that difference
        for i in range(1, len(arr)):
            if arr[i] - arr[i - 1] == minDiff:
                ans.append([arr[i - 1], arr[i]])

        return ans
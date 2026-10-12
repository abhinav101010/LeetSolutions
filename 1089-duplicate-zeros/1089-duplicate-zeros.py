class Solution:
    def duplicateZeros(self, arr: List[int]) -> None:
        """
        Do not return anything, modify arr in-place instead.
        """
        ans = []

        for num in arr:
            if num == 0:
                ans.append(0)
                ans.append(0)
            else:
                ans.append(num)

        for i in range(len(arr)):
            arr[i] = ans[i]
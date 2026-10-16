class Solution:
    def canThreePartsEqualSum(self, arr):
        total = sum(arr)
        if total % 3 != 0: return False
        target = total // 3
        count = 0
        cur = 0
        for i in range(len(arr)):
            cur += arr[i]
            if cur == target:
                count += 1
                cur = 0
        return count >= 3

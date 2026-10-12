class Solution:
    def canThreePartsEqualSum(self, arr: List[int]) -> bool:
        total = sum(arr)

        if total % 3 != 0:
            return False

        target = total // 3
        curr = 0
        parts = 0

        for num in arr:
            curr += num

            if curr == target:
                parts += 1
                curr = 0

        return parts >= 3
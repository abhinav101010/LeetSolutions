class Solution:
    def advantageCount(self, A: list[int], B: list[int]) -> list[int]:
        n = len(A)
        sortedA = sorted(A)
        # B with indices
        sortedB = sorted([(b, i) for i, b in enumerate(B)])
        res = [0]*n
        left = 0
        right = n-1
        for b, i in reversed(sortedB):
            if sortedA[right] > b:
                res[i] = sortedA[right]
                right -= 1
            else:
                res[i] = sortedA[left]
                left += 1
        return res

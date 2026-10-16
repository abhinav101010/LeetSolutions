class Solution:
    def minRoundingError(self, prices, target):
        # not exact; simple approach
        diff = []
        low = high = 0
        for p in prices:
            f = float(p)
            i = int(f)
            low += i
            if f == i:
                high += i
                diff.append(0)
            else:
                high += i + 1
                diff.append(min(f-i, i+1-f))
        if target < low or target > high: return -1
        need = target - low
        diff.sort()
        res = sum(diff)
        for d in diff[:need]:
            res = res - d + (1-d)
        return '{:.3f}'.format(res)

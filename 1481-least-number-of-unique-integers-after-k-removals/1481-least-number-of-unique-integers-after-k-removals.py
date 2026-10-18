class Solution:
    def findLeastNumOfUniqueInts(self, arr, k):
        cnt = Counter(arr)
        for i, v in enumerate(sorted(cnt.values())):
            k -= v
            if k < 0:
                return len(cnt) - i
        return 0

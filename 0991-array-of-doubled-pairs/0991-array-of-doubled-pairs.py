from collections import Counter
class Solution:
    def canReorderDoubled(self, arr):
        count = Counter(arr)
        for x in sorted(count.keys(), key=abs):
            if count[x] == 0:
                continue
            if count[2*x] < count[x]:
                return False
            count[2*x] -= count[x]
        return True

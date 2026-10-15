class Solution:
    def canReorderDoubled(self, arr: list[int]) -> bool:
        from collections import Counter
        cnt = Counter(arr)
        for x in sorted(cnt.keys(), key=abs):
            if cnt[x] > cnt[2*x]:
                return False
            cnt[2*x] -= cnt[x]
        return True

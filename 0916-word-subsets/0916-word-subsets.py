class Solution:
    def wordSubsets(self, A: list[str], B: list[str]) -> list[str]:
        need = [0]*26
        for b in B:
            cnt = [0]*26
            for ch in b:
                cnt[ord(ch)-ord('a')] += 1
            for i in range(26):
                need[i] = max(need[i], cnt[i])
        res = []
        for a in A:
            cnt = [0]*26
            for ch in a:
                cnt[ord(ch)-ord('a')] += 1
            if all(cnt[i] >= need[i] for i in range(26)):
                res.append(a)
        return res

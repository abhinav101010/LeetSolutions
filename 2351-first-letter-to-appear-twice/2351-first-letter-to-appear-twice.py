class Solution:
    def repeatedCharacter(self, s) :
        cnt = Counter()
        for c in s:
            cnt[c] += 1
            if cnt[c] == 2:
                return c

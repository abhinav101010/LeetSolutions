from collections import Counter
class Solution:
    def countCharacters(self, words, chars):
        cnt = Counter(chars)
        ans = 0
        for w in words:
            wc = Counter(w)
            ok = True
            for ch, v in wc.items():
                if cnt[ch] < v:
                    ok = False
                    break
            if ok:
                ans += len(w)
        return ans

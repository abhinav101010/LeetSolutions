class Solution:
    def maxRepOpt1(self, text: str) -> int:
        cnt = {}
        for ch in text:
            cnt[ch] = cnt.get(ch, 0) + 1
        n = len(text)
        ans = 0
        i = 0
        while i < n:
            j = i
            while j < n and text[j] == text[i]:
                j += 1
            l = j - i
            k = j + 1
            while k < n and text[k] == text[i]:
                k += 1
            r = k - j - 1
            ans = max(ans, min(l + r + 1, cnt[text[i]]))
            i = j
        return ans

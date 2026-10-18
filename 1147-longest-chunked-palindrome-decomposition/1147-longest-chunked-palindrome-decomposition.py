class Solution:
    def longestDecomposition(self, text: str) -> int:
        n = len(text)
        ans = 0
        i, j = 0, n - 1
        while i <= j:
            k = 1
            ok = False
            while i + k - 1 < j - k + 1:
                if text[i:i+k] == text[j-k+1:j+1]:
                    ans += 2
                    i += k
                    j -= k
                    ok = True
                    break
                k += 1
            if not ok:
                ans += 1
                break
        return ans

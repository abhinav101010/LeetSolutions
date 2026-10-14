class Solution:
    def minWindow(self, S: str, T: str) -> str:
        n, m = len(S), len(T)
        if m == 0:
            return ""
        best_len = float('inf')
        best_start = -1
        i = 0
        while i < n:
            if S[i] != T[0]:
                i += 1
                continue
            # forward match
            j = i
            k = 0
            while j < n and k < m:
                if S[j] == T[k]:
                    k += 1
                j += 1
            if k != m:  # didn't match all
                break  # no further start will work because we consumed S? Actually we can move i forward.
                # But we can just i+=1 and continue.
                # Simpler: i+=1 and continue.
            # now j is one past the end of matched subsequence
            end = j - 1
            # backward to tighten start
            k = m - 1
            start = end
            while k >= 0:
                if S[start] == T[k]:
                    k -= 1
                start -= 1
            start += 1  # after loop start is one before actual start
            window_len = end - start + 1
            if window_len < best_len or (window_len == best_len and start < best_start):
                best_len = window_len
                best_start = start
            i = start + 1  # next possible start after current start
        if best_start == -1:
            return ""
        return S[best_start:best_start+best_len]

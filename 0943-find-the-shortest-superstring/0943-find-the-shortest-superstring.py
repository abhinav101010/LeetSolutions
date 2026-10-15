class Solution:
    def shortestSuperstring(self, A: list[str]) -> str:
        n = len(A)
        # compute overlap
        overlap = [[0]*n for _ in range(n)]
        for i in range(n):
            for j in range(n):
                if i == j:
                    continue
                a, b = A[i], A[j]
                max_olap = min(len(a), len(b))
                for k in range(max_olap, -1, -1):
                    if a.endswith(b[:k]):
                        overlap[i][j] = k
                        break
        # dp[mask][last] = shortest superstring for subset mask ending with last
        dp = [[""]*n for _ in range(1<<n)]
        for i in range(n):
            dp[1<<i][i] = A[i]
        for mask in range(1<<n):
            for last in range(n):
                if not (mask & (1<<last)):
                    continue
                cur = dp[mask][last]
                if cur == "":
                    continue
                for nxt in range(n):
                    if mask & (1<<nxt):
                        continue
                    nxt_mask = mask | (1<<nxt)
                    # append nxt after last with overlap
                    cand = cur + A[nxt][overlap[last][nxt]:]
                    if dp[nxt_mask][nxt] == "" or len(cand) < len(dp[nxt_mask][nxt]) or (len(cand) == len(dp[nxt_mask][nxt]) and cand < dp[nxt_mask][nxt]):
                        dp[nxt_mask][nxt] = cand
        # answer is min over last of dp[full][last]
        full = (1<<n) - 1
        ans = None
        for last in range(n):
            s = dp[full][last]
            if s == "":
                continue
            if ans is None or len(s) < len(ans) or (len(s) == len(ans) and s < ans):
                ans = s
        return ans

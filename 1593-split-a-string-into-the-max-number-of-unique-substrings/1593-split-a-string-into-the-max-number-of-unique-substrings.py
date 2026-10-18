class Solution:
    def maxUniqueSplit(self, s):
        def dfs(i):
            nonlocal ans
            if len(st) + len(s) - i <= ans:
                return
            if i >= len(s):
                ans = max(ans, len(st))
                return
            for j in range(i + 1, len(s) + 1):
                if s[i:j] not in st:
                    st.add(s[i:j])
                    dfs(j)
                    st.remove(s[i:j])

        ans = 0
        st = set()
        dfs(0)
        return ans

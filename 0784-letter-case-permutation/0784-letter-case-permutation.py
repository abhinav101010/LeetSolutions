class Solution:
    def letterCasePermutation(self, s: str) -> list[str]:
        res = []
        def dfs(i, cur):
            if i == len(s):
                res.append(''.join(cur))
                return
            if s[i].isalpha():
                cur.append(s[i].lower())
                dfs(i+1, cur)
                cur.pop()
                cur.append(s[i].upper())
                dfs(i+1, cur)
                cur.pop()
            else:
                cur.append(s[i])
                dfs(i+1, cur)
                cur.pop()
        dfs(0, [])
        return res

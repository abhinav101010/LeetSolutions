from typing import List

class Solution:
    def smallestSufficientTeam(self, req_skills: List[str], people: List[List[str]]) -> List[int]:
        m = len(req_skills)
        n = len(people)
        skill_to_idx = {s: i for i, s in enumerate(req_skills)}
        p = [0] * n
        for i, skills in enumerate(people):
            for s in skills:
                p[i] |= 1 << skill_to_idx[s]
        total = 1 << m
        f = [n + 1] * total
        g = [0] * total
        h = [0] * total
        f[0] = 0
        for i in range(total):
            if f[i] == n + 1:
                continue
            for j in range(n):
                nxt = i | p[j]
                if f[i] + 1 < f[nxt]:
                    f[nxt] = f[i] + 1
                    g[nxt] = j
                    h[nxt] = i
        ans = []
        i = total - 1
        while i:
            ans.append(g[i])
            i = h[i]
        return ans
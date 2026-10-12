class Solution:
    def buddyStrings(self, s: str, goal: str) -> bool:
        if len(s) != len(goal): return False

        if s == goal:
            return len(set(s)) < len(s)

        wrongIdx = []
        for i in range(len(s)):
            if s[i] != goal[i]:
                wrongIdx.append(i)

        if len(wrongIdx) != 2:
            return False

        s = list(s)
        s[wrongIdx[0]], s[wrongIdx[1]] = \
            s[wrongIdx[1]], s[wrongIdx[0]]
        s = "".join(s)

        return s == goal
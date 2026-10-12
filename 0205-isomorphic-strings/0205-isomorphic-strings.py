class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        mapStoT = {}
        mapTtoS = {}

        for i in range(len(s)):
            if s[i] in mapStoT and t[i] in mapTtoS:
                if mapStoT[s[i]] != t[i] or mapTtoS[t[i]] != s[i]:
                    return False
            elif s[i] not in mapStoT and t[i] not in mapTtoS:
                mapStoT[s[i]] = t[i]
                mapTtoS[t[i]] = s[i]
            else:
                return False
        return True
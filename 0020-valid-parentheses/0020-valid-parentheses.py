class Solution:
    def isValid(self, s: str) -> bool:
        openP = []
        for c in s:
            if c == "(": openP.append(c); continue
            if c == "{": openP.append(c); continue
            if c == "[": openP.append(c); continue

            if len(openP) == 0: return False

            if c == ")" and openP[len(openP)-1] == "(": openP.pop(); continue
            elif c == "}" and openP[len(openP)-1] == "{": openP.pop(); continue
            elif c == "]" and openP[len(openP)-1] == "[": openP.pop(); continue
            else: return False


        if len(openP) > 0: return False
        return True

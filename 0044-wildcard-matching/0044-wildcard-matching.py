class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        # if len(p) > len(s): return False

        # si = 0
        # pi = 0

        # while si<=len(s)-1:
        #     if pi >= len(p): return False
        #     if s[si] == p[pi]:
        #         si+=1
        #         pi+=1
        #         print("Case1")
        #         continue

        #     if s[si] != p[pi] and p[pi] == "?":
        #         si+=1
        #         pi+=1
        #         print("Case2")
        #         continue

        #     if s[si] != p[pi] and s[si] == s[si-1] and p[pi] == "*":
        #         si+=1
        #         print("Case3")
        #         continue
            
        #     return False

        # return True

        # si = pi = 0
        # starI = -1
        # while si <= len(s)-1:
        #     if pi >= len(p): return False
        #     if p[pi] == "*": starI = pi

        #     if s[si] == p[pi]: 
        #         pi+=1
        #         si+=1
        #         continue
        #     elif s[si] != p[pi] and p[pi] == "?":
        #         pi+=1
        #         si+=1
        #         continue
        #     elif p[pi] == "*" and p[pi+1] == s[si]:
        #         starI = -1
        #     elif starI > -1 or p[pi] == "*":
        #         si+=1
        #         starI = pi

        #     return False
        # return True

        si = pi = 0

        starI = -1      # last '*' position in pattern
        match = -1      # where '*' started matching in string

        while si < len(s):

            # Normal character or '?'
            if pi < len(p) and (p[pi] == s[si] or p[pi] == "?"):
                si += 1
                pi += 1

            # Found a '*'
            elif pi < len(p) and p[pi] == "*":
                starI = pi
                match = si
                pi += 1          # Try letting '*' match nothing first

            # Mismatch, but we've seen a '*'
            elif starI != -1:
                pi = starI + 1   # Go back to after '*'
                match += 1
                si = match       # Let '*' absorb one more character

            # No '*' to save us
            else:
                return False

        # Remaining pattern must all be '*'
        while pi < len(p) and p[pi] == "*":
            pi += 1

        return pi == len(p)













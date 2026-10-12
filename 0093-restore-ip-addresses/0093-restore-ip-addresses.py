class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
# STAND PROUD, completely self thought andn implemented
        ans = set()
        def permute(curr, i, dots):
            if i == len(s):
                if dots == 3:
                    ans.add(curr[1:])
                return
            
            oneChar = s[i:i+1]
            twoChar = s[i:i+2]
            threeChar = s[i:i+3]
            if oneChar and dots < 3:
                permute(curr+"."+oneChar, i+1, dots+1)

            if twoChar and twoChar[0] != "0" and dots < 3:
                permute(curr+"."+twoChar, i+2, dots+1)

            if threeChar and int(threeChar) < 256 and threeChar[0] != "0" and dots < 3:
                permute(curr+"."+threeChar, i+3, dots+1)
        permute("",0, -1)
        return list(ans)
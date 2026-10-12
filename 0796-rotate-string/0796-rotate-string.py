class Solution:
    def rotateString(self, s: str, goal: str) -> bool:
        # firstC = s[0]
        # goalToCompare = goal[goal.find(firstC):]
        # sToCompare = s[:s.find(goal[-1])+1]

        # if sToCompare == goalToCompare: 
        #     goalToCompare = goal[:goal.find(firstC)]
        #     sToCompare = s[s.find(goal[-1])+1:]

        #     if sToCompare == goalToCompare: return True
        
        # return False


        if len(goal) == len(s) and str(s+s).find(goal) > -1:
            return True
        return False
            
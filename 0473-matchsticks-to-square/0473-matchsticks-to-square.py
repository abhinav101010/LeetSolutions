from typing import List

class Solution:
    def makesquare(self, matchsticks: List[int]) -> bool:
        if len(matchsticks) < 4:
            return False
        total = sum(matchsticks)
        if total % 4 != 0:
            return False
        target = total // 4
        matchsticks.sort(reverse=True)
        if matchsticks[0] > target:
            return False
        
        sides = [0] * 4
        
        def dfs(index):
            if index == len(matchsticks):
                return sides[0] == sides[1] == sides[2] == target
            
            for i in range(4):
                if sides[i] + matchsticks[index] <= target:
                    sides[i] += matchsticks[index]
                    if dfs(index + 1):
                        return True
                    sides[i] -= matchsticks[index]
                if sides[i] == 0:
                    break
            return False
        
        return dfs(0)
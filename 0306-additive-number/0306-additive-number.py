class Solution:
    def isAdditiveNumber(self, num: str) -> bool:
        n = len(num)
        
        def backtrack(i: int, path: List[int]) -> bool:
            if i == n:
                return len(path) >= 3
            
            for j in range(i, n):
                if j > i and num[i] == '0':
                    break
                curr_str = num[i:j+1]
                curr = int(curr_str)
                
                if len(path) < 2 or curr == path[-1] + path[-2]:
                    path.append(curr)
                    if backtrack(j + 1, path):
                        return True
                    path.pop()
            
            return False
        
        return backtrack(0, [])
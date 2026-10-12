from typing import List

class Solution:
    def addOperators(self, num: str, target: int) -> List[str]:
        result = []
        n = len(num)
        
        def backtrack(index: int, path: str, eval_val: int, prev: int):
            if index == n:
                if eval_val == target:
                    result.append(path)
                return
            
            for i in range(index, n):
                if i > index and num[index] == '0':
                    break
                curr_str = num[index:i+1]
                curr = int(curr_str)
                
                if index == 0:
                    backtrack(i + 1, curr_str, curr, curr)
                else:
                    backtrack(i + 1, path + '+' + curr_str, eval_val + curr, curr)
                    backtrack(i + 1, path + '-' + curr_str, eval_val - curr, -curr)
                    backtrack(i + 1, path + '*' + curr_str, eval_val - prev + prev * curr, prev * curr)
        
        backtrack(0, "", 0, 0)
        return result
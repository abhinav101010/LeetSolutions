from typing import List

class Solution:
    def getFactors(self, n: int) -> List[List[int]]:
        res = []
        
        def dfs(start, path, remain):
            if remain == 1:
                if len(path) > 1:
                    res.append(list(path))
                return
            for i in range(start, int(remain ** 0.5) + 1):
                if remain % i == 0:
                    path.append(i)
                    dfs(i, path, remain // i)
                    path.pop()
            if remain >= start:
                path.append(remain)
                dfs(remain, path, 1)
                path.pop()
        
        dfs(2, [], n)
        return res
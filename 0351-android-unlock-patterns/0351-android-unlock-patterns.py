class Solution:
    def numberOfPatterns(self, m: int, n: int) -> int:
        self.res = 0
        skip = [[0] * 10 for _ in range(10)]
        skip[1][3] = skip[3][1] = 2
        skip[1][7] = skip[7][1] = 4
        skip[3][9] = skip[9][3] = 6
        skip[7][9] = skip[9][7] = 8
        skip[1][9] = skip[9][1] = skip[2][8] = skip[8][2] = skip[3][7] = skip[7][3] = skip[4][6] = skip[6][4] = 5
        visited = set()
        
        def dfs(curr, remain):
            if remain == 0:
                self.res += 1
                return
            for i in range(1, 10):
                if i not in visited:
                    if skip[curr][i] == 0 or skip[curr][i] in visited:
                        visited.add(i)
                        dfs(i, remain - 1)
                        visited.discard(i)
        
        for i in range(1, 10):
            visited.add(i)
            dfs(i, n - 1)
            visited.discard(i)
        ans = 0
        for i in range(m, n + 1):
            ans += self.res // 9  # rough estimate - simpler approach
        # easier: compute directly
        return self._count(m, n, skip)
    
    def _count(self, m, n, skip):
        res_total = 0
        visited = set()
        
        def dfs(curr, remain):
            if remain == 0:
                return 1
            count = 0
            for i in range(1, 10):
                if i not in visited:
                    if skip[curr][i] == 0 or skip[curr][i] in visited:
                        visited.add(i)
                        count += dfs(i, remain - 1)
                        visited.discard(i)
            return count
        
        for len in range(m, n + 1):
            visited.clear()
            for i in range(1, 10):
                visited.add(i)
                res_total += dfs(i, len - 1)
                visited.discard(i)
        return res_total
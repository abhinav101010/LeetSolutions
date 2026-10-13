class Solution:
    def strobogrammaticInRange(self, low: str, high: str) -> int:
        res = 0
        for n in range(len(low), len(high) + 1):
            for s in self.find(n):
                if len(s) == len(low) and s < low:
                    continue
                if len(s) == len(high) and s > high:
                    continue
                res += 1
        return res
    
    def find(self, n: int):
        pairs = [('0','0'), ('1','1'), ('6','9'), ('8','8'), ('9','6')]
        result = []
        def dfs(path, left, right):
            if left > right:
                result.append(''.join(path))
                return
            for a, b in pairs:
                if left == 0 and right == n - 1 and a == '0' and n > 1:
                    continue
                if left == right and a != b:
                    continue
                path[left] = a
                path[right] = b
                dfs(path, left + 1, right - 1)
        dfs([''] * n, 0, n - 1)
        return result
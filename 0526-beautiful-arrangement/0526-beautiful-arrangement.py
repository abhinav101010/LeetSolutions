class Solution:
    def countArrangement(self, n: int) -> int:
        self.count = 0
        used = [False] * (n + 1)
        
        def backtrack(pos):
            if pos > n:
                self.count += 1
                return
            for i in range(1, n + 1):
                if not used[i] and (i % pos == 0 or pos % i == 0):
                    used[i] = True
                    backtrack(pos + 1)
                    used[i] = False
        
        backtrack(1)
        return self.count
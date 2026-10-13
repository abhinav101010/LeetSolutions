class Solution:
    def findStrobogrammatic(self, n: int):
        self.res = []
        pairs = [('0','0'), ('1','1'), ('6','9'), ('8','8'), ('9','6')]
        def backtrack(s, left, right):
            if left > right:
                self.res.append(''.join(s))
                return
            for a, b in pairs:
                if left == 0 and right == n - 1 and a == '0' and n > 1:
                    continue
                if left == right and a != b:
                    continue
                s[left] = a
                s[right] = b
                backtrack(s, left + 1, right - 1)
        backtrack([''] * n, 0, n - 1)
        return self.res
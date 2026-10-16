class Solution:
    def strWithout3a3b(self, a, b):
        res = []
        i = j = 0
        while i < a or j < b:
            if len(res) >= 2 and res[-1] == res[-2] == 'a':
                res.append('b'); j += 1
            elif len(res) >= 2 and res[-1] == res[-2] == 'b':
                res.append('a'); i += 1
            elif i < a and (j >= b or i > j):
                res.append('a'); i += 1
            else:
                res.append('b'); j += 1
        return ''.join(res)

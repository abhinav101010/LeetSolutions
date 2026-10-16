class Solution:
    def confusingNumber(self, n):
        mp = {'0':'0','1':'1','6':'9','8':'8','9':'6'}
        s = str(n)
        for c in s:
            if c not in mp:
                return False
        rot = ''.join(mp[c] for c in s[::-1])
        return rot != s

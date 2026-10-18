class Solution:
    def minimumChairs(self, s):
        cnt = left = 0
        for c in s:
            if c == "E":
                if left:
                    left -= 1
                else:
                    cnt += 1
            else:
                left += 1
        return cnt

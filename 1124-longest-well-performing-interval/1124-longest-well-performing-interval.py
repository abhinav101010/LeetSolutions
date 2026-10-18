class Solution:
    def longestWPI(self, hours):
        cur=0; seen={0:-1}; best=0
        for i,h in enumerate(hours):
            cur += 1 if h>8 else -1
            if cur>0: best=i+1
            elif cur-1 in seen: best=max(best,i-seen[cur-1])
            if cur not in seen: seen[cur]=i
        return best
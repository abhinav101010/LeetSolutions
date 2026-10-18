class Solution:
    def numSquarefulPerms(self, nums):
        import collections
        c=collections.Counter(nums)
        keys=list(c)
        n=len(nums)
        def is_sq(x):
            r=int(x**0.5); return r*r==x
        res=0
        def dfs(last, rem):
            nonlocal res
            if rem==0: res+=1; return
            for k in keys:
                if c[k]>0 and (last is None or is_sq(last+k)):
                    c[k]-=1; dfs(k,rem-1); c[k]+=1
        dfs(None,n)
        return res

class Solution:
    def movesToMakeZigzag(self, nums):
        n=len(nums)
        def cost(start):
            res=0; a=nums[:]
            for i in range(start,n,2):
                need=min(a[i-1] if i>0 else 10**9, a[i+1] if i+1<n else 10**9)-1
                if a[i]>need: res+=a[i]-need; a[i]=need
            return res
        return min(cost(0),cost(1))

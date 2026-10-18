class Solution:
    def mctFromLeafValues(self, arr):
        import functools
        n=len(arr)
        @functools.lru_cache(None)
        def dp(i,j):
            if i==j: return 0
            best=10**9
            for k in range(i,j):
                best=min(best,dp(i,k)+dp(k+1,j)+max(arr[i:k+1])*max(arr[k+1:j+1]))
            return best
        return dp(0,n-1)
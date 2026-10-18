class Solution:
    def maxAbsValExpr(self, arr1, arr2):
        n=len(arr1); best=0
        for s1 in (1,-1):
            for s2 in (1,-1):
                for s3 in (1,-1):
                    vals=[s1*arr1[i]+s2*arr2[i]+s3*i for i in range(n)]
                    best=max(best,max(vals)-min(vals))
        return best

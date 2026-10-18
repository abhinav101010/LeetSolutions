class Solution {
    public int maxAbsValExpr(int[] arr1, int[] arr2) {
        int n=arr1.length, best=0;
        for(int s1:new int[]{-1,1}) for(int s2:new int[]{-1,1}) for(int s3:new int[]{-1,1}){
            int mx=Integer.MIN_VALUE, mn=Integer.MAX_VALUE;
            for(int i=0;i<n;i++){int v=s1*arr1[i]+s2*arr2[i]+s3*i; mx=Math.max(mx,v); mn=Math.min(mn,v);}
            best=Math.max(best,mx-mn);
        }
        return best;
    }}

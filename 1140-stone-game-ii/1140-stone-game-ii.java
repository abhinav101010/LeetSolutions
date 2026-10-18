class Solution {
    public int stoneGameII(int[] piles) {
        int n=piles.length; int[] suffix=new int[n+1];
        for(int i=n-1;i>=0;i--) suffix[i]=suffix[i+1]+piles[i];
        Integer[][] memo=new Integer[n][n+1];
        return dp(piles,suffix,memo,0,1);
    }
    int dp(int[] piles,int[] suffix,Integer[][] memo,int i,int m){
        int n=piles.length;
        if(i>=n) return 0;
        if(i+2*m>=n) return suffix[i];
        if(memo[i][m]!=null) return memo[i][m];
        int best=0;
        for(int x=1;x<=2*m;x++) best=Math.max(best,suffix[i]-dp(piles,suffix,memo,i+x,Math.max(m,x)));
        return memo[i][m]=best;
    }}

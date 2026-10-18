class Solution {
    public int mctFromLeafValues(int[] arr) {
        int n=arr.length; int[][] dp=new int[n][n], mx=new int[n][n];
        for(int i=0;i<n;i++){mx[i][i]=arr[i]; for(int j=i+1;j<n;j++) mx[i][j]=Math.max(mx[i][j-1],arr[j]);}
        for(int len=2;len<=n;len++) for(int i=0;i+len<=n;i++){
            int j=i+len-1; dp[i][j]=Integer.MAX_VALUE;
            for(int k=i;k<j;k++) dp[i][j]=Math.min(dp[i][j],dp[i][k]+dp[k+1][j]+mx[i][k]*mx[k+1][j]);
        }
        return dp[0][n-1];
    }
}
class Solution {
    public int largest1BorderedSquare(int[][] grid) {
        int m=grid.length, n=grid[0].length;
        int[][] up=new int[m][n], left=new int[m][n];
        for(int i=0;i<m;i++) for(int j=0;j<n;j++) if(grid[i][j]==1){
            up[i][j]=(i>0?up[i-1][j]:0)+1; left[i][j]=(j>0?left[i][j-1]:0)+1;
        }
        int best=0;
        for(int i=0;i<m;i++) for(int j=0;j<n;j++) for(int k=Math.min(up[i][j],left[i][j]);k>best;k--){
            if(up[i][j-k+1]>=k && left[i-k+1][j]>=k){best=k;break;}
        }
        return best*best;
    }}

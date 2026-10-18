class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        vector<vector<int>> up(m,vector<int>(n,0)), left(m,vector<int>(n,0));
        for(int i=0;i<m;i++) for(int j=0;j<n;j++) if(grid[i][j]){
            up[i][j]=(i?up[i-1][j]:0)+1; left[i][j]=(j?left[i][j-1]:0)+1;
        }
        int best=0;
        for(int i=0;i<m;i++) for(int j=0;j<n;j++) for(int k=min(up[i][j],left[i][j]);k>best;k--){
            if(up[i][j-k+1]>=k && left[i-k+1][j]>=k){best=k;break;}
        }
        return best*best;
    }}

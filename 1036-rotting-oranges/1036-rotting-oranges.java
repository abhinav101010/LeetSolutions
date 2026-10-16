import java.util.*;
class Solution {
    public int orangesRotting(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        Queue<int[]> q = new LinkedList<>();
        int fresh = 0;
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                if (grid[i][j]==2) q.offer(new int[]{i,j});
                else if (grid[i][j]==1) fresh++;
            }
        }
        int time = 0;
        int[][] dirs = {{-1,0},{1,0},{0,-1},{0,1}};
        while (!q.isEmpty() && fresh > 0) {
            int sz = q.size();
            for (int k=0;k<sz;k++) {
                int[] cur = q.poll();
                for (int[] d:dirs) {
                    int nx=cur[0]+d[0], ny=cur[1]+d[1];
                    if (nx>=0&&nx<m&&ny>=0&&ny<n&&grid[nx][ny]==1) {
                        grid[nx][ny]=2;
                        fresh--;
                        q.offer(new int[]{nx,ny});
                    }
                }
            }
            time++;
        }
        return fresh==0?time:-1;
    }
}

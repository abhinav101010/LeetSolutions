import java.util.*;

class Solution {
    public List<List<Integer>> pacificAtlantic(int[][] heights) {
        List<List<Integer>> result = new ArrayList<>();
        if (heights == null || heights.length == 0) return result;
        
        int m = heights.length, n = heights[0].length;
        boolean[][] pacific = new boolean[m][n];
        boolean[][] atlantic = new boolean[m][n];
        
        Queue<int[]> pacificQ = new LinkedList<>();
        Queue<int[]> atlanticQ = new LinkedList<>();
        
        for (int i = 0; i < m; i++) {
            pacific[i][0] = true;
            pacificQ.offer(new int[]{i, 0});
            atlantic[i][n-1] = true;
            atlanticQ.offer(new int[]{i, n-1});
        }
        for (int j = 0; j < n; j++) {
            pacific[0][j] = true;
            pacificQ.offer(new int[]{0, j});
            atlantic[m-1][j] = true;
            atlanticQ.offer(new int[]{m-1, j});
        }
        
        bfs(heights, pacificQ, pacific);
        bfs(heights, atlanticQ, atlantic);
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    result.add(Arrays.asList(i, j));
                }
            }
        }
        return result;
    }
    
    private void bfs(int[][] heights, Queue<int[]> queue, boolean[][] visited) {
        int m = heights.length, n = heights[0].length;
        int[][] dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        
        while (!queue.isEmpty()) {
            int[] curr = queue.poll();
            int x = curr[0], y = curr[1];
            for (int[] d : dirs) {
                int nx = x + d[0], ny = y + d[1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny] && heights[nx][ny] >= heights[x][y]) {
                    visited[nx][ny] = true;
                    queue.offer(new int[]{nx, ny});
                }
            }
        }
    }
}
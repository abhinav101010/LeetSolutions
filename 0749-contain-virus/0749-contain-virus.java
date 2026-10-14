import java.util.*;

class Solution {
    private static final int[][] DIRS = {{1,0},{-1,0},{0,1},{0,-1}};
    
    public int containVirus(int[][] isInfected) {
        int n = isInfected.length;
        int m = isInfected[0].length;
        int ans = 0;
        
        while (true) {
            // find regions
            boolean[][] visited = new boolean[n][m];
            List<Region> regions = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (isInfected[i][j] == 1 && !visited[i][j]) {
                        Region reg = bfs(isInfected, visited, i, j, n, m);
                        regions.add(reg);
                    }
                }
            }
            if (regions.isEmpty()) break;
            
            // find region with max threatened cells
            int maxThreat = -1;
            int idx = -1;
            for (int i = 0; i < regions.size(); i++) {
                int threat = regions.get(i).threatened.size();
                if (threat > maxThreat) {
                    maxThreat = threat;
                    idx = i;
                }
            }
            if (maxThreat == 0) break; // no spread possible
            
            // add walls for selected region
            ans += regions.get(idx).walls;
            
            // spread virus from other regions, contain selected region
            for (int i = 0; i < regions.size(); i++) {
                Region reg = regions.get(i);
                if (i == idx) {
                    // contain: mark as 2
                    for (int[] cell : reg.cells) {
                        isInfected[cell[0]][cell[1]] = 2;
                    }
                } else {
                    // spread
                    for (int[] cell : reg.cells) {
                        int x = cell[0];
                        int y = cell[1];
                        for (int[] dir : DIRS) {
                            int nx = x + dir[0];
                            int ny = y + dir[1];
                            if (nx >= 0 && nx < n && ny >= 0 && ny < m && isInfected[nx][ny] == 0) {
                                isInfected[nx][ny] = 1;
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
    
    private Region bfs(int[][] grid, boolean[][] visited, int si, int sj, int n, int m) {
        Queue<int[]> q = new LinkedList<>();
        q.offer(new int[]{si, sj});
        visited[si][sj] = true;
        List<int[]> cells = new ArrayList<>();
        Set<String> threatened = new HashSet<>();
        int walls = 0;
        while (!q.isEmpty()) {
            int[] cur = q.poll();
            int x = cur[0], y = cur[1];
            cells.add(new int[]{x, y});
            for (int[] dir : DIRS) {
                int nx = x + dir[0];
                int ny = y + dir[1];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    if (grid[nx][ny] == 1) {
                        if (!visited[nx][ny]) {
                            visited[nx][ny] = true;
                            q.offer(new int[]{nx, ny});
                        }
                    } else { // uninfected
                        threatened.add(nx + "," + ny);
                        walls++;
                    }
                }
                // out of bounds: no wall needed
            }
        }
        return new Region(cells, threatened, walls);
    }
    
    private static class Region {
        List<int[]> cells;
        Set<String> threatened;
        int walls;
        Region(List<int[]> cells, Set<String> threatened, int walls) {
            this.cells = cells;
            this.threatened = threatened;
            this.walls = walls;
        }
    }
}

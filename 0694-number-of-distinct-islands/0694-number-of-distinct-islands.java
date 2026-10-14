import java.util.*;

class Solution {
    public int numDistinctIslands(int[][] grid) {
        if (grid == null || grid.length == 0 || grid[0].length == 0) {
            return 0;
        }
        int rows = grid.length;
        int cols = grid[0].length;
        boolean[][] visited = new boolean[rows][cols];
        Set<String> shapes = new HashSet<>();
        int[][] dirs = {{0,1},{1,0},{0,-1},{-1,0}};
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 1 && !visited[r][c]) {
                    List<int[]> cells = new ArrayList<>();
                    Deque<int[]> stack = new ArrayDeque<>();
                    stack.push(new int[]{r, c});
                    visited[r][c] = true;
                    while (!stack.isEmpty()) {
                        int[] cur = stack.pop();
                        int cr = cur[0], cc = cur[1];
                        cells.add(cur);
                        for (int[] dir : dirs) {
                            int nr = cr + dir[0];
                            int nc = cc + dir[1];
                            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == 1 && !visited[nr][nc]) {
                                visited[nr][nc] = true;
                                stack.push(new int[]{nr, nc});
                            }
                        }
                    }
                    // normalize
                    int minR = Integer.MAX_VALUE, minC = Integer.MAX_VALUE;
                    for (int[] cell : cells) {
                        minR = Math.min(minR, cell[0]);
                        minC = Math.min(minC, cell[1]);
                    }
                    List<int[]> normalized = new ArrayList<>();
                    for (int[] cell : cells) {
                        normalized.add(new int[]{cell[0] - minR, cell[1] - minC});
                    }
                    // sort by row then col
                    normalized.sort(Comparator.comparingInt((int[] a) -> a[0])
                                            .thenComparingInt(a -> a[1]));
                    StringBuilder sb = new StringBuilder();
                    for (int[] cell : normalized) {
                        sb.append(cell[0]).append(',').append(cell[1]).append(';');
                    }
                    shapes.add(sb.toString());
                }
            }
        }
        return shapes.size();
    }
}

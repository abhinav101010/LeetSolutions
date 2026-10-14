import java.util.*;

class Solution {
    public String findShortestWay(int[][] maze, int[] ball, int[] hole) {
        int m = maze.length, n = maze[0].length;
        int[][] dirs = {{-1,0},{1,0},{0,-1},{0,1}};
        char[] dirChar = {'u','d','l','r'};
        int[][] dist = new int[m][n];
        String[][] path = new String[m][n];
        for (int i = 0; i < m; i++) {
            Arrays.fill(dist[i], Integer.MAX_VALUE);
            Arrays.fill(path[i], "");
        }
        PriorityQueue<Node> pq = new PriorityQueue<>((a, b) -> {
            if (a.dist != b.dist) {
                return Integer.compare(a.dist, b.dist);
            }
            return a.path.compareTo(b.path);
        });
        int sx = ball[0], sy = ball[1];
        dist[sx][sy] = 0;
        path[sx][sy] = "";
        pq.offer(new Node(sx, sy, 0, ""));
        while (!pq.isEmpty()) {
            Node cur = pq.poll();
            int x = cur.x, y = cur.y;
            int d = cur.dist;
            String p = cur.path;
            if (d > dist[x][y] || (d == dist[x][y] && p.compareTo(path[x][y]) > 0)) {
                continue;
            }
            if (x == hole[0] && y == hole[1]) {
                return p;
            }
            for (int i = 0; i < 4; i++) {
                int nx = x, ny = y;
                int steps = 0;
                while (nx + dirs[i][0] >= 0 && nx + dirs[i][0] < m &&
                       ny + dirs[i][1] >= 0 && ny + dirs[i][1] < n &&
                       maze[nx + dirs[i][0]][ny + dirs[i][1]] == 0) {
                    nx += dirs[i][0];
                    ny += dirs[i][1];
                    steps++;
                    if (nx == hole[0] && ny == hole[1]) {
                        break;
                    }
                }
                int nd = d + steps;
                String np = p + dirChar[i];
                if (nd < dist[nx][ny] || (nd == dist[nx][ny] && np.compareTo(path[nx][ny]) < 0)) {
                    dist[nx][ny] = nd;
                    path[nx][ny] = np;
                    pq.offer(new Node(nx, ny, nd, np));
                }
            }
        }
        return "impossible";
    }
    class Node {
        int x, y;
        int dist;
        String path;
        Node(int x, int y, int dist, String path) {
            this.x = x;
            this.y = y;
            this.dist = dist;
            this.path = path;
        }
    }
}

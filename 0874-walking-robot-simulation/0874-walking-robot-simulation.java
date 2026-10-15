import java.util.*;
class Solution {
    public int robotSim(int[] commands, int[][] obstacles) {
        Set<Long> obs = new HashSet<>();
        for (int[] o : obstacles) {
            long key = ((long) o[0] + 30000) << 16 | (o[1] + 30000);
            obs.add(key);
        }
        int[] dx = {0, 1, 0, -1};
        int[] dy = {1, 0, -1, 0};
        int x = 0, y = 0, di = 0; // north
        int ans = 0;
        for (int cmd : commands) {
            if (cmd == -2) {
                di = (di + 3) % 4;
            } else if (cmd == -1) {
                di = (di + 1) % 4;
            } else {
                for (int step = 0; step < cmd; step++) {
                    int nx = x + dx[di];
                    int ny = y + dy[di];
                    long key = ((long) nx + 30000) << 16 | (ny + 30000);
                    if (obs.contains(key)) {
                        break;
                    }
                    x = nx;
                    y = ny;
                    int dist = x*x + y*y;
                    if (dist > ans) ans = dist;
                }
            }
        }
        return ans;
    }
}

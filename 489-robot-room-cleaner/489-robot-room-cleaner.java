import java.util.*;

/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its interface
 */
interface Robot {
    // Returns true if the cell in front is open and robot moves into the cell.
    // Returns false if the cell in front is blocked and robot stays in the current cell.
    boolean move();

    // Robot will stay in the same cell after calling turnLeft/turnRight.
    // Each turn will be 90 degrees.
    void turnLeft();

    // Robot will stay in the same cell after calling turnLeft/turnRight.
    // Each turn will be 90 degrees.
    void turnRight();

    // Clean the current cell.
    void clean();
}

class Solution {
    private static final int[][] DIRS = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // up, right, down, left
    private Set<String> visited = new HashSet<>();
    
    public void cleanRoom(Robot robot) {
        dfs(0, 0, 0, robot);
    }
    
    private void dfs(int x, int y, int dir, Robot robot) {
        String key = x + "," + y;
        visited.add(key);
        robot.clean();
        
        for (int i = 0; i < 4; i++) {
            int newDir = (dir + i) % 4;
            int nx = x + DIRS[newDir][0];
            int ny = y + DIRS[newDir][1];
            String nkey = nx + "," + ny;
            if (!visited.contains(nkey) && robot.move()) {
                dfs(nx, ny, newDir, robot);
                // go back
                robot.turnRight();
                robot.turnRight();
                robot.move();
                robot.turnLeft();
                robot.turnLeft();
            }
            // turn to next direction
            robot.turnRight();
        }
    }
}

#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

// This is the robot's control interface.
// You should not implement it, or speculate about its interface
class Robot {
public:
    // Returns true if the cell in front is open and robot moves into the cell.
    // Returns false if the cell in front is blocked and robot stays in the current cell.
    virtual bool move() = 0;

    // Robot will stay in the same cell after calling turnLeft/turnRight.
    // Each turn will be 90 degrees.
    virtual void turnLeft() = 0;

    // Robot will stay in the same cell after calling turnLeft/turnRight.
    // Each turn will be 90 degrees.
    virtual void turnRight() = 0;

    // Clean the current cell.
    virtual void clean() = 0;
};

class Solution {
private:
    static const vector<pair<int,int>> dirs; // up, right, down, left
    unordered_set<string> visited;
    
    void goBack(Robot& robot) {
        robot.turnRight();
        robot.turnRight();
        robot.move();
        robot.turnLeft();
        robot.turnLeft();
    }
    
    void dfs(int x, int y, int d, Robot& robot) {
        string key = to_string(x) + "," + to_string(y);
        visited.insert(key);
        robot.clean();
        
        for (int i = 0; i < 4; i++) {
            int newDir = (d + i) % 4;
            int nx = x + dirs[newDir].first;
            int ny = y + dirs[newDir].second;
            string nkey = to_string(nx) + "," + to_string(ny);
            if (visited.find(nkey) == visited.end() && robot.move()) {
                dfs(nx, ny, newDir, robot);
                goBack(robot);
            }
            // turn the robot to face the next direction
            robot.turnRight();
        }
    }
public:
    void cleanRoom(Robot& robot) {
        dfs(0, 0, 0, robot);
    }
};

// Initialize static member
const vector<pair<int,int>> Solution::dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};

#include <queue>
#include <unordered_set>
#include <string>
#include <vector>
#include <cstdlib>
#include <cmath>
using namespace std;

class Solution {
public:
    int racecar(int target) {
        queue<vector<int>> q;
        unordered_set<string> visited;
        q.push({0, 1});
        visited.insert("0,1");
        int steps = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto cur = q.front(); q.pop();
                int pos = cur[0];
                int speed = cur[1];
                if (pos == target) {
                    return steps;
                }
                // Accelerate
                int newPos = pos + speed;
                int newSpeed = speed * 2;
                string key = to_string(newPos) + "," + to_string(newSpeed);
                if (visited.find(key) == visited.end() && abs(newPos) <= 2 * target) {
                    visited.insert(key);
                    q.push({newPos, newSpeed});
                }
                // Reverse
                int newSpeed2 = speed > 0 ? -1 : 1;
                key = pos + "," + to_string(newSpeed2);
                if (visited.find(key) == visited.end()) {
                    visited.insert(key);
                    q.push({pos, newSpeed2});
                }
            }
            steps++;
        }
        return -1;
    }
};

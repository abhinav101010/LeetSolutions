#include <vector>
#include <set>
#include <cctype>
using namespace std;

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<long long> obs;
        for (auto& o : obstacles) {
            long long key = ((long long) o[0] + 30000) << 16 | (o[1] + 30000);
            obs.insert(key);
        }
        vector<int> dx = {0, 1, 0, -1};
        vector<int> dy = {1, 0, -1, 0};
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
                    long long key = ((long long) nx + 30000) << 16 | (ny + 30000);
                    if (obs.find(key) != obs.end()) {
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
};

#include <string>
#include <queue>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string start;
        for (auto& row : board) {
            for (int num : row) {
                start += ('0' + num);
            }
        }
        string target = "123450";
        if (start == target) return 0;
        vector<vector<int>> neighbors = {
            {1,3},
            {0,2,4},
            {1,5},
            {0,4},
            {1,3,5},
            {2,4}
        };
        queue<string> q;
        unordered_set<string> visited;
        q.push(start);
        visited.insert(start);
        int steps = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                string cur = q.front(); q.pop();
                if (cur == target) return steps;
                int zeroIdx = cur.find('0');
                for (int nb : neighbors[zeroIdx]) {
                    string nxt = cur;
                    swap(nxt[zeroIdx], nxt[nb]);
                    if (visited.find(nxt) == visited.end()) {
                        visited.insert(nxt);
                        q.push(nxt);
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};

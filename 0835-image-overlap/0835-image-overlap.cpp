#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        unordered_map<string, int> count;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (img1[i][j] == 1) {
                    for (int x = 0; x < n; x++) {
                        for (int y = 0; y < n; y++) {
                            if (img2[x][y] == 1) {
                                string key = to_string(x - i) + "," + to_string(y - j);
                                count[key]++;
                            }
                        }
                    }
                }
            }
        }
        int max = 0;
        for (auto& p : count) {
            max = max(max, p.second);
        }
        return max;
    }
};

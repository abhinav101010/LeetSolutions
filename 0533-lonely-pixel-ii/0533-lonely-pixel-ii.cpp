#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int findBlackPixel(vector<vector<char>>& picture, int N) {
        if (picture.empty() || picture[0].empty()) return 0;
        int m = picture.size(), n = picture[0].size();
        vector<int> rows(m, 0), cols(n, 0);
        vector<string> rowStr(m);
        for (int i = 0; i < m; i++) {
            string s;
            for (int j = 0; j < n; j++) {
                s += picture[i][j];
                if (picture[i][j] == 'B') {
                    rows[i]++;
                    cols[j]++;
                }
            }
            rowStr[i] = s;
        }
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (picture[i][j] == 'B' && rows[i] == N && cols[j] == N) {
                    bool same = true;
                    for (int r = 0; r < m; r++) {
                        if (picture[r][j] == 'B' && rowStr[r] != rowStr[i]) {
                            same = false;
                            break;
                        }
                    }
                    if (same) {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string kthSmallestPath(vector<int>& destination, int k) {
        int rows = destination[0], cols = destination[1];
        string path;
        int v = rows, h = cols;
        for (int i = 0; i < rows + cols; ++i) {
            if (h == 0) {
                path += 'V';
                --v;
                continue;
            }
            if (v == 0) {
                path += 'H';
                --h;
                continue;
            }
            long long combinations = 1;
            for (int j = 1; j <= h - 1; ++j) {
                combinations = combinations * (v + j) / j;
            }
            if (k <= combinations) {
                path += 'H';
                --h;
            } else {
                path += 'V';
                --v;
                k -= combinations;
            }
        }
        return path;
    }
};

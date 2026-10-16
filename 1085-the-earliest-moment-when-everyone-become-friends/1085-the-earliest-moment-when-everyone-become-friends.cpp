#include <vector>
#include <algorithm>
using namespace std;
class Solution {
    vector<int> parent;
    int find(int x) { while (parent[x] != x) { parent[x] = parent[parent[x]]; x = parent[x]; } return x; }
public:
    int earliestAcq(vector<vector<int>>& logs, int N) {
        sort(logs.begin(), logs.end());
        parent.resize(N);
        for (int i = 0; i < N; i++) parent[i] = i;
        int comp = N;
        for (auto& l : logs) {
            int ra = find(l[1]), rb = find(l[2]);
            if (ra != rb) { parent[ra] = rb; comp--; if (comp == 1) return l[0]; }
        }
        return -1;
    }
};

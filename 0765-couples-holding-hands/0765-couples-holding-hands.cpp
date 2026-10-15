#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        vector<int> dsu(n/2);
        for (int i = 0; i < n/2; i++) dsu[i] = i;
        function<int(int)> find = [&](int x) {
            while (dsu[x] != x) {
                dsu[x] = dsu[dsu[x]];
                x = dsu[x];
            }
            return x;
        };
        auto union_op = [&](int a, int b) {
            int ra = find(a);
            int rb = find(b);
            if (ra != rb) {
                dsu[ra] = rb;
            }
        };
        for (int i = 0; i < n; i += 2) {
            int a = row[i] / 2;
            int b = row[i+1] / 2;
            union_op(a, b);
        }
        unordered_set<int> roots;
        for (int i = 0; i < n/2; i++) {
            roots.insert(find(i));
        }
        return (n/2) - (int)roots.size();
    }
};

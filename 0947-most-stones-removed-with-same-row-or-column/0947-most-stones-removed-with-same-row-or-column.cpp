#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        const int offset = 10001;
        vector<int> parent(2 * offset);
        for (int i = 0; i < 2 * offset; i++) parent[i] = i;
        function<int(int)> find = [&](int x) {
            while (parent[x] != x) {
                parent[x] = parent[parent[x]];
                x = parent[x];
            }
            return x;
        };
        auto unite = [&](int a, int b) {
            int ra = find(a);
            int rb = find(b);
            if (ra != rb) {
                parent[rb] = ra;
            }
        };
        for (auto& stone : stones) {
            int x = stone[0];
            int y = stone[1];
            unite(x, y + offset);
        }
        unordered_set<int> roots;
        for (auto& stone : stones) {
            int x = stone[0];
            roots.insert(find(x));
        }
        return n - (int)roots.size();
    }
};

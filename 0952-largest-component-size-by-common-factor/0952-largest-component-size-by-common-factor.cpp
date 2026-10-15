#include <vector>
#include <unordered_map>
#include <functional>
using namespace std;

class Solution {
public:
    int largestComponentSize(vector<int>& A) {
        int n = A.size();
        int maxA = 0;
        for (int v : A) if (v > maxA) maxA = v;
        vector<int> parent(maxA + 1);
        vector<int> size(maxA + 1, 1);
        for (int i = 0; i <= maxA; i++) parent[i] = i;
        function<int(int)> getRoot = [&](int x) {
            while (parent[x] != x) {
                parent[x] = parent[parent[x]];
                x = parent[x];
            }
            return x;
        };
        auto unite = [&](int a, int b) {
            int ra = getRoot(a);
            int rb = getRoot(b);
            if (ra == rb) return;
            if (size[ra] < size[rb]) swap(ra, rb);
            parent[rb] = ra;
            size[ra] += size[rb];
        };
        unordered_map<int, int> primeToNum;
        for (int num : A) {
            int x = num;
            for (int t = 2; t * t <= x; t++) {
                if (x % t == 0) {
                    if (!primeToNum.count(t)) {
                        primeToNum[t] = num;
                    } else {
                        unite(num, primeToNum[t]);
                    }
                    while (x % t == 0) {
                        x /= t;
                    }
                }
            }
            if (x > 1) {
                if (!primeToNum.count(x)) {
                    primeToNum[x] = num;
                } else {
                    unite(num, primeToNum[x]);
                }
            }
        }
        unordered_map<int, int> cnt;
        for (int num : A) {
            int root = getRoot(num);
            cnt[root]++;
        }
        int ans = 0;
        for (auto& p : cnt) {
            if (p.second > ans) ans = p.second;
        }
        return ans;
    }
};

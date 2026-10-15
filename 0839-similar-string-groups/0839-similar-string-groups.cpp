#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        vector<int> parent(n);
        vector<int> rank(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (similar(strs[i], strs[j])) {
                    union(parent, rank, i, j);
                }
            }
        }
        unordered_set<int> set;
        for (int i = 0; i < n; i++) {
            set.insert(find(parent, i));
        }
        return set.size();
    }
private:
    bool similar(const string& a, const string& b) {
        if (a == b) return true;
        vector<int> diff;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) {
                diff.push_back(i);
                if (diff.size() > 2) return false;
            }
        }
        if (diff.size() != 2) return false;
        int i = diff[0];
        int j = diff[1];
        return a[i] == b[j] && a[j] == b[i];
    }
    int find(vector<int>& parent, int x) {
        while (parent[x] != x) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }
    void union(vector<int>& parent, vector<int>& rank, int x, int y) {
        int rx = find(parent, x);
        int ry = find(parent, y);
        if (rx == ry) return;
        if (rank[rx] < rank[ry]) {
            parent[rx] = ry;
        } else if (rank[rx] > rank[ry]) {
            parent[ry] = rx;
        } else {
            parent[ry] = rx;
            rank[rx]++;
        }
    }
};

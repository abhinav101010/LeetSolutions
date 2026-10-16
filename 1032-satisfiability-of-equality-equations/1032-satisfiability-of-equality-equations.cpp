#include <string>
#include <vector>
using namespace std;
class Solution {
    vector<int> parent;
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    void uni(int x,int y) {
        parent[find(x)] = find(y);
    }
public:
    bool equationsPossible(vector<string>& equations) {
        parent.assign(26,0);
        for (int i=0;i<26;i++) parent[i]=i;
        for (auto &eq : equations) {
            if (eq[1]=='=') {
                uni(eq[0]-'a', eq[3]-'a');
            }
        }
        for (auto &eq : equations) {
            if (eq[1]=='!') {
                if (find(eq[0]-'a') == find(eq[3]-'a')) return false;
            }
        }
        return true;
    }
};

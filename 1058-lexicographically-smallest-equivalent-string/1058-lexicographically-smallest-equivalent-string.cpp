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
        int p1 = find(x), p2 = find(y);
        if (p1 < p2) parent[p2] = p1;
        else parent[p1] = p2;
    }
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        parent.assign(26,0);
        for (int i=0;i<26;i++) parent[i]=i;
        for (int i=0;i<s1.size();i++) uni(s1[i]-'a', s2[i]-'a');
        string res;
        for (char c:baseStr) {
            int p = find(c-'a');
            res += ('a'+p);
        }
        return res;
    }
};

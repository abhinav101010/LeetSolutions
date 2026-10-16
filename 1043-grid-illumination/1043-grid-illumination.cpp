#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;
struct PairHash {
    size_t operator()(const pair<int,int> &p) const {
        return (size_t)p.first*2000000000ULL + (size_t)p.second;
    }
};
class Solution {
public:
    vector<int> gridIllumination(int N, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        unordered_map<int,int> rows,cols,d1,d2;
        unordered_set<pair<int,int>, PairHash> ls;
        for (auto &l:lamps) {
            if (ls.find({l[0],l[1]})==ls.end()) {
                ls.insert({l[0],l[1]});
                rows[l[0]]++; cols[l[1]]++; d1[l[0]-l[1]]++; d2[l[0]+l[1]]++;
            }
        }
        vector<int> res(queries.size());
        for (int qi=0;qi<queries.size();qi++) {
            int x=queries[qi][0], y=queries[qi][1];
            if (rows[x]||cols[y]||d1[x-y]||d2[x+y]) res[qi]=1;
            else res[qi]=0;
            for (int nx=max(0,x-1); nx<min(N,x+2); nx++) {
                for (int ny=max(0,y-1); ny<min(N,y+2); ny++) {
                    auto p=make_pair(nx,ny);
                    if (ls.find(p)!=ls.end()) {
                        ls.erase(p);
                        rows[nx]--; cols[ny]--; d1[nx-ny]--; d2[nx+ny]--;
                    }
                }
            }
        }
        return res;
    }
};

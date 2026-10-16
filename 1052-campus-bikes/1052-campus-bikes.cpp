#include <vector>
#include <algorithm>
using namespace std;
struct P {
    int d,i,j;
};
class Solution {
public:
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int n = workers.size(), m = bikes.size();
        vector<P> pairs;
        for (int i=0;i<n;i++) {
            int x1=workers[i][0], y1=workers[i][1];
            for (int j=0;j<m;j++) {
                int x2=bikes[j][0], y2=bikes[j][1];
                int d = abs(x1-x2)+abs(y1-y2);
                pairs.push_back({d,i,j});
            }
        }
        sort(pairs.begin(), pairs.end(), [](auto a,auto b){return a.d<b.d;});
        vector<int> res(n,-1);
        vector<bool> used(m,false);
        for (auto &p:pairs) {
            if (res[p.i]==-1 && !used[p.j]) {
                res[p.i]=p.j; used[p.j]=true;
            }
            int cnt=0; for (bool b:used) if (b) cnt++;
            if (cnt==n) break;
        }
        return res;
    }
};

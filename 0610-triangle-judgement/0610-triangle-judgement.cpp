#include <vector>
#include <string>
using namespace std;
struct Triangle { int x,y,z; };
class Solution {
public:
    vector<vector<string>> triangleJudgement(vector<Triangle> t) {
        vector<vector<string>> r;
        for (auto &x : t) {
            string yes = (x.x+x.y>x.z && x.x+x.z>x.y && x.y+x.z>x.x) ? "Yes" : "No";
            r.push_back({to_string(x.x),to_string(x.y),to_string(x.z),yes});
        }
        return r;
    }
};

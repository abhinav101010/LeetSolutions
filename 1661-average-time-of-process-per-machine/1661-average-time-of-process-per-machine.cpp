#include <vector>
#include <string>
#include <map>
using namespace std;
struct Act { int machine_id; int process_id; string activity_type; double timestamp; };
class Solution {
public:
    vector<pair<int,double>> avgTime(vector<Act> acts) {
        map<pair<int,int>, pair<double,double>> m; // start,end
        for (auto &a : acts) {
            if (a.activity_type=="start") m[{a.machine_id,a.process_id}].first=a.timestamp;
            else m[{a.machine_id,a.process_id}].second=a.timestamp;
        }
        map<int,vector<double>> bym;
        for (auto &kv : m) bym[kv.first.first].push_back(kv.second.second-kv.second.first);
        vector<pair<int,double>> r;
        for (auto &kv : bym) {
            double s=0; for(double d:kv.second) s+=d;
            r.push_back({kv.first, s/kv.second.size()});
        }
        return r;
    }
};

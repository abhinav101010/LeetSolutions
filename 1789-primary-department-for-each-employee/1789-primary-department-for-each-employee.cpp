#include <vector>
#include <string>
#include <map>
#include <set>
using namespace std;
struct Emp { int employee_id; int department_id; char primary_flag; };
class Solution {
public:
    vector<pair<int,int>> primaryDept(vector<Emp> e) {
        map<int,int> cnt;
        for (auto &x : e) cnt[x.employee_id]++;
        vector<pair<int,int>> r;
        for (auto &x : e) {
            if (x.primary_flag=='Y' || cnt[x.employee_id]==1) {
                // avoid dup
            }
        }
        set<pair<int,int>> seen;
        for (auto &x : e) {
            if (x.primary_flag=='Y' || cnt[x.employee_id]==1) {
                if (seen.insert({x.employee_id,x.department_id}).second)
                    r.push_back({x.employee_id,x.department_id});
            }
        }
        return r;
    }
};

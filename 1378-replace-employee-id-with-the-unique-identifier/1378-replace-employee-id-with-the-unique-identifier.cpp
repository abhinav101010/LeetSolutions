#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
struct Emp { int id; string name; };
struct Uni { int id; int unique_id; };
class Solution {
public:
    vector<vector<string>> getEmployeeNames(vector<Emp> emps, vector<Uni> unis) {
        unordered_map<int,int> m;
        for (auto &u : unis) m[u.id]=u.unique_id;
        vector<vector<string>> r;
        for (auto &e : emps) {
            string uid = m.count(e.id) ? to_string(m[e.id]) : "";
            r.push_back({uid, e.name});
        }
        return r;
    }
};

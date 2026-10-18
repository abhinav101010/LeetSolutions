#include <vector>
#include <string>
#include <map>
using namespace std;

struct Employee { int empId; string eventDay; int inTime; int outTime; };

class Solution {
public:
    vector<vector<string>> findTotalTimeSpentByEachEmployee(vector<Employee>& employees) {
        map<pair<string, int>, int> total;
        for (auto& e : employees) total[{e.eventDay, e.empId}] += (e.outTime - e.inTime);
        vector<vector<string>> res;
        for (auto& kv : total) {
            res.push_back({kv.first.first, to_string(kv.first.second), to_string(kv.second)});
        }
        return res;
    }
};

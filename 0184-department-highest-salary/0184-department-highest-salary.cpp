#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

struct Employee { int id; string name; int salary; int departmentId; };
struct Department { int id; string name; };

class Solution {
public:
    vector<vector<string>> departmentHighestSalary(vector<Employee>& employees, vector<Department>& departments) {
        unordered_map<int, string> deptName;
        for (auto& d : departments) deptName[d.id] = d.name;
        unordered_map<int, int> maxSal;
        for (auto& e : employees) {
            auto it = maxSal.find(e.departmentId);
            if (it == maxSal.end() || e.salary > it->second) maxSal[e.departmentId] = e.salary;
        }
        vector<vector<string>> res;
        for (auto& e : employees) {
            if (deptName.find(e.departmentId) == deptName.end()) continue;
            auto it = maxSal.find(e.departmentId);
            if (it != maxSal.end() && e.salary == it->second) {
                res.push_back({deptName[e.departmentId], e.name, to_string(e.salary)});
            }
        }
        return res;
    }
};

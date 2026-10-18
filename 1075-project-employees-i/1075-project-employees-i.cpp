#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <cstdio>
using namespace std;

struct Project {
    int project_id;
    int employee_id;
};

struct Employee {
    int employee_id;
    string name;
    int experience_years;
};

class Solution {
public:
    static string fmt2(double x) {
        char buf[64];
        snprintf(buf, sizeof(buf), "%.2f", x);
        return string(buf);
    }
    vector<vector<string>> projectEmployees(const vector<Project>& projects, const vector<Employee>& employees) {
        map<int, int> empExp;
        for (const auto& e : employees) empExp[e.employee_id] = e.experience_years;
        map<int, pair<double, int>> proj;
        for (const auto& p : projects) {
            auto it = empExp.find(p.employee_id);
            if (it == empExp.end()) continue;
            proj[p.project_id].first += it->second;
            proj[p.project_id].second += 1;
        }
        vector<vector<string>> result;
        for (const auto& kv : proj) {
            double avg = kv.second.first / kv.second.second;
            result.push_back({to_string(kv.first), fmt2(avg)});
        }
        return result;
    }
};

#include <vector>
#include <string>
#include <optional>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;

struct Employee {
    int employee_id;
    string name;
    optional<int> reports_to;
    int age;
};

struct Report {
    int employee_id;
    string name;
    int reports_count;
    int average_age;
};

class Solution {
public:
    vector<Report> countEmployees(vector<Employee>& employees) {
        map<int, int> cnt;
        map<int, long long> sumAge;
        for (const Employee& e : employees) {
            if (e.reports_to.has_value()) {
                int m = e.reports_to.value();
                cnt[m]++;
                sumAge[m] += e.age;
            }
        }
        vector<Report> ans;
        for (const Employee& e : employees) {
            auto it = cnt.find(e.employee_id);
            if (it != cnt.end() && it->second >= 1) {
                int avg = (int)round((double)sumAge[e.employee_id] / (double)it->second);
                ans.push_back({e.employee_id, e.name, it->second, avg});
            }
        }
        sort(ans.begin(), ans.end(), [](const Report& a, const Report& b) {
            return a.employee_id < b.employee_id;
        });
        return ans;
    }
};

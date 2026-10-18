#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct Employee {
    int Id;
    int Month;
    int Salary;
};

class Solution {
public:
    vector<vector<string>> cumulativeSalary(vector<Employee>& employees) {
        unordered_map<int, vector<Employee>> byId;
        for (auto& e : employees) byId[e.Id].push_back(e);
        vector<vector<string>> ans;
        for (auto& kv : byId) {
            int id = kv.first;
            vector<Employee>& rows = kv.second;
            sort(rows.begin(), rows.end(), [](const Employee& a, const Employee& b) {
                return a.Month < b.Month;
            });
            int maxMonth = rows.back().Month;
            int n = (int)rows.size();
            for (int i = 0; i < n; i++) {
                int sum = rows[i].Salary;
                if (i - 1 >= 0) sum += rows[i - 1].Salary;
                if (i - 2 >= 0) sum += rows[i - 2].Salary;
                if (rows[i].Month == maxMonth) sum -= rows[i].Salary;
                ans.push_back({to_string(id), to_string(rows[i].Month), to_string(sum)});
            }
        }
        sort(ans.begin(), ans.end(), [](const vector<string>& a, const vector<string>& b) {
            if (a[0] != b[0]) return stoi(a[0]) < stoi(b[0]);
            return stoi(a[1]) < stoi(b[1]);
        });
        return ans;
    }
};

#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <numeric>
using namespace std;

struct Employee {
    int Id;
    int Company;
    int Salary;
};

class Solution {
public:
    vector<vector<string>> medianEmployeeSalary(vector<Employee>& employees) {
        unordered_map<int, vector<Employee>> byComp;
        for (auto& e : employees) byComp[e.Company].push_back(e);
        vector<vector<string>> ans;
        for (auto& kv : byComp) {
            int comp = kv.first;
            vector<Employee>& rows = kv.second;
            int n = (int)rows.size();
            vector<int> ascIdx(n), descIdx(n);
            iota(ascIdx.begin(), ascIdx.end(), 0);
            iota(descIdx.begin(), descIdx.end(), 0);
            sort(ascIdx.begin(), ascIdx.end(), [&](int a, int b) {
                if (rows[a].Salary != rows[b].Salary) return rows[a].Salary < rows[b].Salary;
                return a < b;
            });
            sort(descIdx.begin(), descIdx.end(), [&](int a, int b) {
                if (rows[a].Salary != rows[b].Salary) return rows[a].Salary > rows[b].Salary;
                return a < b;
            });
            vector<int> rnAsc(n), rnDesc(n);
            for (int i = 0; i < n; i++) {
                rnAsc[ascIdx[i]] = i + 1;
                rnDesc[descIdx[i]] = i + 1;
            }
            for (int i = 0; i < n; i++) {
                int ra = rnAsc[i], rd = rnDesc[i];
                if (ra == rd || ra == rd - 1 || ra == rd + 1) {
                    ans.push_back({to_string(rows[i].Id), to_string(comp), to_string(rows[i].Salary)});
                }
            }
        }
        sort(ans.begin(), ans.end(), [](const vector<string>& a, const vector<string>& b) {
            if (a[1] != b[1]) return stoi(a[1]) < stoi(b[1]);
            return stoi(a[0]) < stoi(b[0]);
        });
        return ans;
    }
};

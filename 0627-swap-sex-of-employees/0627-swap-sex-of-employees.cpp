#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Salary {
    int id;
    string name;
    string sex;
    int salary;
};

class Solution {
public:
    vector<vector<string>> swapSex(vector<Salary>& salaries) {
        vector<vector<string>> ans;
        for (auto& s : salaries) {
            string sex = s.sex;
            if (sex == "m") sex = "f";
            else if (sex == "f") sex = "m";
            ans.push_back({to_string(s.id), s.name, sex, to_string(s.salary)});
        }
        sort(ans.begin(), ans.end(), [](const vector<string>& a, const vector<string>& b) {
            return stoi(a[0]) < stoi(b[0]);
        });
        return ans;
    }
};

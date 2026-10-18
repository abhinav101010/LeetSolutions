#include <vector>
#include <string>
using namespace std;

struct Employee {
    int empId;
    string name;
    int supervisor;
    int salary;
};

struct Bonus {
    int empId;
    int bonus;
};

class Solution {
public:
    vector<vector<string>> employeeBonus(vector<Employee>& employees, vector<Bonus>& bonusList) {
        vector<vector<string>> result;
        for (const auto& e : employees) {
            bool found = false;
            int bonusVal = 0;
            for (const auto& b : bonusList) {
                if (b.empId == e.empId) {
                    found = true;
                    bonusVal = b.bonus;
                    break;
                }
            }
            if (!found || bonusVal < 1000) {
                vector<string> row;
                row.push_back(e.name);
                row.push_back(found ? to_string(bonusVal) : "null");
                result.push_back(row);
            }
        }
        return result;
    }
};

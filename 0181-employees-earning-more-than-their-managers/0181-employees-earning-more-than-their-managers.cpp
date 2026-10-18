#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Employee {
    int id;
    string name;
    int salary;
    int managerId; // -1 if no manager
};

class Solution {
public:
    vector<string> findEmployees(vector<Employee>& employees) {
        vector<string> result;
        for (const auto& e : employees) {
            if (e.managerId == 0) continue; // handle as no manager if 0
            // find manager
            for (const auto& m : employees) {
                if (m.id == e.managerId) {
                    if (e.salary > m.salary) {
                        result.push_back(e.name);
                    }
                    break;
                }
            }
        }
        return result;
    }
};

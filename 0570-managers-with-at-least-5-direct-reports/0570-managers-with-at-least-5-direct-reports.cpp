#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct Employee {
    int id;
    string name;
    int managerId; // -1 if no manager
};

class Solution {
public:
    vector<string> findManagers(vector<Employee>& employees) {
        vector<string> result;
        unordered_map<int, int> managerCount;
        unordered_map<int, string> nameMap;
        for (const auto& e : employees) {
            nameMap[e.id] = e.name;
            if (e.managerId >= 0) { // has manager
                managerCount[e.managerId]++;
            }
        }
        for (const auto& [managerId, count] : managerCount) {
            if (count >= 5) {
                result.push_back(nameMap[managerId]);
            }
        }
        // Sort by manager name if needed? The SQL just returns names; not specified to sort
        // But Leetcode usually doesn't require specific order unless stated
        sort(result.begin(), result.end());
        return result;
    }
};

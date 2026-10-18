#include <vector>
#include <string>
#include <set>
using namespace std;

struct Employee {
    int id;
    int salary;
};

class Solution {
public:
    vector<vector<string>> secondHighestSalary(const vector<Employee>& employees) {
        set<int> distinct;
        for (const auto& e : employees) distinct.insert(e.salary);
        vector<vector<string>> result;
        if (distinct.size() < 2) {
            result.push_back({"NULL"});
            return result;
        }
        auto it = distinct.rbegin();
        ++it;
        result.push_back({to_string(*it)});
        return result;
    }
};

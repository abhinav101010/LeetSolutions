#include <vector>
#include <set>
#include <algorithm>

using namespace std;

struct Employee { int id; int salary; };

class Solution {
public:
    int getNthHighestSalary(vector<Employee> employees, int N) {
        set<int> distinct;
        for (auto &e : employees) distinct.insert(e.salary);
        vector<int> v(distinct.rbegin(), distinct.rend());
        if (N < 1 || N > (int)v.size()) return -1; // null represented as -1? 
        return v[N-1];
    }
};

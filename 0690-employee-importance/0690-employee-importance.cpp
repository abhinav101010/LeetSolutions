#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> map;
        for (auto e : employees) {
            map[e->id] = e;
        }
        int total = 0;
        queue<int> q;
        q.push(id);
        while (!q.empty()) {
            int eid = q.front(); q.pop();
            Employee* e = map[eid];
            total += e->importance;
            for (int sub : e->subordinates) {
                q.push(sub);
            }
        }
        return total;
    }
};

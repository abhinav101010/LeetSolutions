#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <map>

using namespace std;

struct Department {
    int id;
    string name;
};

struct Student {
    int id;
    string name;
    int department_id;
};

class Solution {
public:
    vector<pair<string, int> > countStudents(vector<Department> &departments, vector<Student> &students) {
        unordered_map<int, int> cnt;
        for (const auto &s : students) {
            cnt[s.department_id]++;
        }
        vector<pair<string, int> > res;
        for (const auto &d : departments) {
            res.push_back({d.name, cnt[d.id]});
        }
        sort(res.begin(), res.end(), [](const auto &a, const auto &b) {
            if (a.second != b.second) return a.second > b.second;
            return a.first < b.first;
        });
        return res;
    }
};

#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <map>

using namespace std;

struct Course {
    string student;
    string className;
};

class Solution {
public:
    vector<string> findClasses(vector<Course> &courses) {
        unordered_map<string, int> cnt;
        for (const auto &c : courses) {
            cnt[c.className]++;
        }
        vector<string> res;
        for (const auto &p : cnt) {
            if (p.second >= 5) {
                res.push_back(p.first);
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};

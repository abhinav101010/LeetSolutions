#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

struct Student { int studentId; string studentName; };
struct Subject { string subjectName; };
struct Examination { int studentId; string subjectName; };

class Solution {
public:
    vector<vector<string>> studentsAndExaminations(vector<Student>& students, vector<Subject>& subjects, vector<Examination>& examinations) {
        unordered_map<string, int> examCount;
        for (auto& e : examinations) {
            string key = to_string(e.studentId) + "|" + e.subjectName;
            examCount[key]++;
        }
        vector<vector<string>> res;
        for (auto& s : students) {
            for (auto& sub : subjects) {
                string key = to_string(s.studentId) + "|" + sub.subjectName;
                int cnt = 0;
                auto it = examCount.find(key);
                if (it != examCount.end()) cnt = it->second;
                res.push_back({to_string(s.studentId), s.studentName, sub.subjectName, to_string(cnt)});
            }
        }
        sort(res.begin(), res.end(), [](const vector<string>& a, const vector<string>& b) {
            int ai = stoi(a[0]), bi = stoi(b[0]);
            if (ai != bi) return ai < bi;
            return a[2] < b[2];
        });
        return res;
    }
};

#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

struct SurveyLog {
    int question_id;
    string action;
};

class Solution {
public:
    vector<vector<string>> highestAnswerRate(const vector<SurveyLog>& log) {
        map<int, pair<int, int>> q;
        for (const auto& l : log) {
            auto& pr = q[l.question_id];
            if (l.action == "answer") pr.first++;
            else if (l.action == "show") pr.second++;
        }
        struct Row { int qid; double rate; };
        vector<Row> rows;
        for (const auto& kv : q) {
            if (kv.second.first > 0) {
                double rate = (kv.second.second == 0) ? 0.0 : (double)kv.second.first / kv.second.second;
                rows.push_back({kv.first, rate});
            }
        }
        sort(rows.begin(), rows.end(), [](const Row& a, const Row& b) {
            if (a.rate != b.rate) return a.rate > b.rate;
            return a.qid < b.qid;
        });
        vector<vector<string>> result;
        if (!rows.empty()) result.push_back({to_string(rows[0].qid)});
        return result;
    }
};

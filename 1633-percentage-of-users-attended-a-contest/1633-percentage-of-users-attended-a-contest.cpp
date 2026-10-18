#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <cstdio>
using namespace std;

struct User {
    int user_id;
    string user_name;
};

struct Register {
    int contest_id;
    int user_id;
};

class Solution {
public:
    static string fmt2(double x) {
        char buf[64];
        snprintf(buf, sizeof(buf), "%.2f", x);
        return string(buf);
    }
    vector<vector<string>> percentageAttended(const vector<User>& users, const vector<Register>& reg) {
        int total = (int)users.size();
        map<int, int> cnt;
        for (const auto& r : reg) cnt[r.contest_id]++;
        struct Row { int contest_id; double pct; };
        vector<Row> rows;
        for (const auto& kv : cnt) {
            if (total == 0) continue;
            rows.push_back({kv.first, kv.second * 100.0 / total});
        }
        sort(rows.begin(), rows.end(), [](const Row& a, const Row& b) {
            if (a.pct != b.pct) return a.pct > b.pct;
            return a.contest_id < b.contest_id;
        });
        vector<vector<string>> result;
        for (const auto& r : rows)
            result.push_back({to_string(r.contest_id), fmt2(r.pct)});
        return result;
    }
};

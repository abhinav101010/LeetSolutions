#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <tuple>
#include <algorithm>
using namespace std;

struct DailySales {
    string date_id;
    string make_name;
    int lead_id;
    int partner_id;
};

class Solution {
public:
    vector<vector<string>> dailyLeadsAndPartners(vector<DailySales>& sales) {
        unordered_map<string, unordered_set<int>> leads;
        unordered_map<string, unordered_set<int>> partners;
        // group by date_id+make_name
        for (const auto& s : sales) {
            string key = s.date_id + "|" + s.make_name;
            leads[key].insert(s.lead_id);
            partners[key].insert(s.partner_id);
        }
        vector<vector<string>> res;
        for (const auto& [key, ls] : leads) {
            // parse key
            size_t pos = key.find('|');
            string date_id = key.substr(0, pos);
            string make_name = key.substr(pos + 1);
            int lcount = ls.size();
            int pcount = partners[key].size();
            res.push_back({date_id, make_name, to_string(lcount), to_string(pcount)});
        }
        // sort for consistent output
        sort(res.begin(), res.end(), [](auto& a, auto& b) {
            if (a[0] != b[0]) return a[0] < b[0];
            return a[1] < b[1];
        });
        return res;
    }
};

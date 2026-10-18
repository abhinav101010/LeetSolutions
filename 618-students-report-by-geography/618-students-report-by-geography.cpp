#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

struct Student {
    string name;
    string continent;
};

class Solution {
public:
    vector<tuple<string, string, string> > report(vector<Student> &students) {
        map<string, vector<string> > by_cont;
        for (const auto &s : students) {
            by_cont[s.continent].push_back(s.name);
        }
        // sort each continent list
        for (auto &p : by_cont) {
            sort(p.second.begin(), p.second.end());
        }
        // find max size
        size_t maxn = 0;
        for (const auto &p : by_cont) {
            if (p.second.size() > maxn) maxn = p.second.size();
        }
        vector<tuple<string, string, string> > res;
        for (size_t i = 0; i < maxn; ++i) {
            string am = "";
            string as = "";
            string eu = "";
            if (by_cont.count("America") && i < by_cont["America"].size()) am = by_cont["America"][i];
            if (by_cont.count("Asia") && i < by_cont["Asia"].size()) as = by_cont["Asia"][i];
            if (by_cont.count("Europe") && i < by_cont["Europe"].size()) eu = by_cont["Europe"][i];
            res.push_back(make_tuple(am, as, eu));
        }
        return res;
    }
};

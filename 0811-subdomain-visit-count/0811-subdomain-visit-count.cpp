#include <vector>
#include <string>
#include <unordered_map>
#include <sstream>
using namespace std;

class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> cnt;
        for (string& cp : cpdomains) {
            stringstream ss(cp);
            string countStr;
            ss >> countStr;
            int count = stoi(countStr);
            string domain;
            ss >> domain;
            // split domain by '.'
            int start = 0;
            for (int i = 0; i <= domain.size(); i++) {
                if (i == domain.size() || domain[i] == '.') {
                    string sub = domain.substr(start, i - start);
                    cnt[sub] += count;
                    start = i + 1;
                }
            }
        }
        vector<string> res;
        for (auto& p : cnt) {
            res.push_back(to_string(p.second) + " " + p.first);
        }
        return res;
    }
};

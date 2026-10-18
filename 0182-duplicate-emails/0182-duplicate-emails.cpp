#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct Person {
    int id;
    string email;
};

class Solution {
public:
    vector<vector<string>> duplicateEmails(vector<Person>& persons) {
        unordered_map<string, int> cnt;
        for (auto& p : persons) cnt[p.email]++;
        vector<vector<string>> ans;
        for (auto& kv : cnt) {
            if (kv.second > 1) ans.push_back({kv.first});
        }
        return ans;
    }
};

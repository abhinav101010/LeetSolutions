#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

struct User {
    int user_id;
    string name;
};

class Solution {
public:
    vector<pair<int, string> > fixNames(vector<User> &users) {
        vector<pair<int, string> > res;
        for (const auto &u : users) {
            string fixed = u.name;
            if (!fixed.empty()) {
                fixed[0] = toupper(fixed[0]);
                for (size_t i = 1; i < fixed.size(); ++i) {
                    fixed[i] = tolower(fixed[i]);
                }
            }
            res.push_back({u.user_id, fixed});
        }
        sort(res.begin(), res.end());
        return res;
    }
};

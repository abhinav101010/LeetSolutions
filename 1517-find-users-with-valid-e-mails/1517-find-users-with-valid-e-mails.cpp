#include <vector>
#include <string>
#include <regex>
using namespace std;

struct User {
    int user_id;
    string name;
    string mail;
};

class Solution {
public:
    vector<User> findUsers(vector<User>& users) {
        vector<User> res;
        regex re("^[A-Za-z][A-Za-z0-9_.-]*@leetcode\\.com$");
        for (const auto& u : users) {
            if (regex_match(u.mail, re)) {
                res.push_back(u);
            }
        }
        return res;
    }
};

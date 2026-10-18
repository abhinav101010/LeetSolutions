#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

struct Login {
    int user_id;
    string time_stamp; // datetime string
};

class Solution {
public:
    vector<pair<int, string> > latestLogin(vector<Login>& logins) {
        vector<pair<int, string> > result;
        map<int, string> userLatest;
        for (const auto& l : logins) {
            // Check if in 2020
            // time_stamp starts with 2020
            if (l.time_stamp.find("2020") == 0) {
                if (userLatest.find(l.user_id) == userLatest.end() || l.time_stamp > userLatest[l.user_id]) {
                    userLatest[l.user_id] = l.time_stamp;
                }
            } else if (l.time_stamp.length() >= 4 && l.time_stamp.substr(0, 4) == "2020") {
                // handle case
                if (userLatest.find(l.user_id) == userLatest.end() || l.time_stamp > userLatest[l.user_id]) {
                    userLatest[l.user_id] = l.time_stamp;
                }
            }
        }
        for (const auto& [uid, ts] : userLatest) {
            // double check
            if (ts.substr(0, 4) == "2020") {
                result.push_back({uid, ts});
            }
        }
        // map is sorted by key; if we need to return in any order per problem, but original order not specified
        return result;
    }
};

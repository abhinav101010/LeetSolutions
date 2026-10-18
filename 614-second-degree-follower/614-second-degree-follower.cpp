#include <vector>
#include <string>
#include <set>
using namespace std;

struct Follow {
    int follower;
    int followee;
};

class Solution {
public:
    vector<vector<string>> secondDegreeFollower(const vector<Follow>& follow) {
        set<int> resultSet;
        for (const auto& f1 : follow) {
            for (const auto& f2 : follow) {
                if (f1.followee == f2.follower)
                    resultSet.insert(f2.followee);
            }
        }
        vector<vector<string>> result;
        for (int x : resultSet) result.push_back({to_string(x)});
        return result;
    }
};

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string findContestMatch(int n) {
        vector<string> teams;
        for (int i = 1; i <= n; i++) {
            teams.push_back(to_string(i));
        }
        while (teams.size() > 1) {
            int half = teams.size() / 2;
            vector<string> newTeams;
            for (int i = 0; i < half; i++) {
                newTeams.push_back("(" + teams[i] + "," + teams[teams.size() - 1 - i] + ")");
            }
            teams = move(newTeams);
        }
        return teams[0];
    }
};

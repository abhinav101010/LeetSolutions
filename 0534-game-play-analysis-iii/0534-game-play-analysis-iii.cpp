#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
struct Activity { int player_id; string event_date; int games_played; };
class Solution {
public:
    vector<vector<string>> gamesPlayedSoFar(vector<Activity> a) {
        sort(a.begin(),a.end(),[](const Activity&x,const Activity&y){ if(x.player_id!=y.player_id) return x.player_id<y.player_id; return x.event_date<y.event_date;});
        vector<vector<string>> r;
        map<int,int> running;
        for (auto &x : a) { running[x.player_id]+=x.games_played; r.push_back({to_string(x.player_id),x.event_date,to_string(running[x.player_id])}); }
        return r;
    }
};

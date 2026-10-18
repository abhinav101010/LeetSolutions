#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <numeric>

using namespace std;

struct User {
    int id;
    string name;
};

struct Ride {
    int id;
    int user_id;
    int distance;
};

class Solution {
public:
    vector<pair<string, int> > topTravellers(vector<User> &users, vector<Ride> &rides) {
        unordered_map<int, int> dist;
        for (const auto &r : rides) {
            dist[r.user_id] += r.distance;
        }
        vector<pair<string, int> > res;
        for (const auto &u : users) {
            res.push_back({u.name, dist[u.id]});
        }
        sort(res.begin(), res.end(), [](const auto &a, const auto &b) {
            if (a.second != b.second) return a.second > b.second;
            return a.first < b.first;
        });
        return res;
    }
};

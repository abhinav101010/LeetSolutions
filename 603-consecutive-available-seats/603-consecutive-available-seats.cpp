#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct Cinema {
    int seat_id;
    int free;
};

class Solution {
public:
    vector<vector<string>> consecutiveAvailableSeats(vector<Cinema>& cinema) {
        unordered_map<int, int> freeMap;
        for (auto& c : cinema) if (c.free == 1) freeMap[c.seat_id] = 1;
        vector<int> seats;
        for (auto& kv : freeMap) seats.push_back(kv.first);
        sort(seats.begin(), seats.end());
        vector<vector<string>> ans;
        for (int sid : seats) {
            if (freeMap.count(sid - 1) || freeMap.count(sid + 1)) {
                ans.push_back({to_string(sid)});
            }
        }
        return ans;
    }
};

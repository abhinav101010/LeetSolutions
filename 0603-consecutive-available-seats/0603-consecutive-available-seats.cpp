#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

struct Seat {
    int id;
    bool free;
};

class Solution {
public:
    vector<int> consecutiveAvailableSeats(vector<Seat>& seats) {
        unordered_set<int> freeIds;
        for (const Seat& s : seats) {
            if (s.free) freeIds.insert(s.id);
        }
        vector<int> ans;
        for (const Seat& s : seats) {
            if (!s.free) continue;
            int id = s.id;
            if (freeIds.count(id - 1) || freeIds.count(id + 1)) {
                ans.push_back(id);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

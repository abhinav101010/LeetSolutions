#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int,int>> cars;
        for (int i = 0; i < n; i++) {
            cars.push_back({position[i], speed[i]});
        }
        sort(cars.begin(), cars.end(), [](const auto& a, const auto& b) {
            return a.first > b.first; // descending position
        });
        int fleets = 0;
        double prevTime = 0.0;
        for (auto& p : cars) {
            double time = (double)(target - p.first) / p.second;
            if (time > prevTime) {
                fleets++;
                prevTime = time;
            }
        }
        return fleets;
    }
};

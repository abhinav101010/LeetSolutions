#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <random>
using namespace std;

class Solution {
private:
    int m;
    unordered_set<int> blackset;
    unordered_map<int, int> map;
    default_random_engine rng;
    uniform_int_distribution<int> dist;
public:
    Solution(int N, vector<int>& blacklist) {
        m = N - (int)blacklist.size();
        for (int b : blacklist) {
            if (b < m) {
                blackset.insert(b);
            }
        }
        int j = m;
        for (int b : blacklist) {
            if (b >= m) continue;
            while (blackset.count(j) || map.count(j)) {
                j++;
            }
            map[b] = j;
            j++;
        }
        rng = default_random_engine(random_device{}());
        dist = uniform_int_distribution<int>(0, m-1);
    }

    int pick() {
        int x = dist(rng);
        auto it = map.find(x);
        if (it != map.end()) return it->second;
        return x;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(N, blacklist);
 * int param_1 = obj->pick();
 */

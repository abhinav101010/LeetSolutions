#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> cnt;
        for (int a : answers) {
            cnt[a]++;
        }
        int total = 0;
        for (auto& p : cnt) {
            int x = p.first;
            int f = p.second;
            int groupSize = x + 1;
            int groups = (f + groupSize - 1) / groupSize; // ceil
            total += groups * groupSize;
        }
        return total;
    }
};

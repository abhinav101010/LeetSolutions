#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> numMovesStonesII(vector<int>& stones) {
        sort(stones.begin(), stones.end());
        int n = stones.size();
        int maxMoves = max(stones[n-1] - stones[1] - n + 2, stones[n-2] - stones[0] - n + 2);
        int minMoves = n;
        int j = 0;
        for (int i = 0; i < n; i++) {
            while (j < n && stones[j] - stones[i] < n) j++;
            int cost = n - (j - i);
            if (j - i == n - 1 && stones[j-1] - stones[i] == n - 2) cost = 2;
            minMoves = min(minMoves, cost);
        }
        return {minMoves, maxMoves};
    }
};

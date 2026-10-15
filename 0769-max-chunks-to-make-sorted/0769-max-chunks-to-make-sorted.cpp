#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int maxSeen = 0;
        int chunks = 0;
        for (int i = 0; i < arr.size(); i++) {
            maxSeen = max(maxSeen, arr[i]);
            if (maxSeen == i) {
                chunks++;
            }
        }
        return chunks;
    }
};

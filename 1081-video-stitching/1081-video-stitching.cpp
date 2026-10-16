#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        sort(clips.begin(), clips.end());
        int res = 0, currEnd = 0, nextEnd = 0, i = 0, n = clips.size();
        while (currEnd < T) {
            while (i < n && clips[i][0] <= currEnd) {
                nextEnd = max(nextEnd, clips[i][1]);
                i++;
            }
            if (nextEnd == currEnd) return -1;
            currEnd = nextEnd;
            res++;
        }
        return res;
    }
};

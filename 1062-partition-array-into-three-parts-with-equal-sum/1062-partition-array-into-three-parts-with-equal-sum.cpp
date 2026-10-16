#include <vector>
#include <numeric>
using namespace std;
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int total = accumulate(arr.begin(), arr.end(), 0);
        if (total % 3 != 0) return false;
        int target = total / 3;
        int count = 0;
        int cur = 0;
        for (int x : arr) {
            cur += x;
            if (cur == target) {
                count++;
                cur = 0;
            }
        }
        return count >= 3;
    }
};

#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int minElement(vector<int>& nums) {
        int m = *min_element(nums.begin(), nums.end());
        int s = 0;
        while (m > 0) { s += m % 10; m /= 10; }
        return s;
    }
};

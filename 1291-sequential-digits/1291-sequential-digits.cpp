#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> result;
        for (int len = 2; len <= 9; len++) {
            for (int start = 1; start + len - 1 <= 9; start++) {
                int num = 0;
                for (int i = 0; i < len; i++) {
                    num = num * 10 + (start + i);
                }
                if (num >= low && num <= high) {
                    result.push_back(num);
                }
            }
        }
        return result;
    }
};
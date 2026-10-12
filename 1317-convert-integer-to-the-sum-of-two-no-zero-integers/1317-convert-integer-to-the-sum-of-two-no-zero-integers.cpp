#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        for (int a = 1; a < n; a++) {
            int b = n - a;
            if (!containsZero(a) && !containsZero(b)) {
                return {a, b};
            }
        }
        return {};
    }
    
private:
    bool containsZero(int num) {
        while (num > 0) {
            if (num % 10 == 0) return true;
            num /= 10;
        }
        return false;
    }
};
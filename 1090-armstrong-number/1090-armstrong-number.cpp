#include <string>
using namespace std;
class Solution {
public:
    bool isArmstrong(int N) {
        string s = to_string(N);
        int k = s.size();
        int sum = 0;
        for (char c : s) sum += pow(c - '0', k);
        return sum == N;
    }
};

#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    bool confusingNumber(int n) {
        unordered_map<char,char> mp {{'0','0'},{'1','1'},{'6','9'},{'8','8'},{'9','6'}};
        string s = to_string(n);
        for (char c : s) if (!mp.count(c)) return false;
        string rot;
        for (int i = s.size()-1; i >= 0; i--) rot += mp[s[i]];
        return rot != s;
    }
};

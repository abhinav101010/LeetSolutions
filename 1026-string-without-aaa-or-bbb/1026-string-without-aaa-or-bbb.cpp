#include <string>
using namespace std;
class Solution {
public:
    string strWithout3a3b(int a, int b) {
        string res;
        int i = 0, j = 0; // used
        while (i < a || j < b) {
            if (res.size() >= 2 && res[res.size()-1]=='a' && res[res.size()-2]=='a') {
                res += 'b'; j++;
            } else if (res.size() >= 2 && res[res.size()-1]=='b' && res[res.size()-2]=='b') {
                res += 'a'; i++;
            } else if (i < a && (j >= b || i > j)) {
                res += 'a'; i++;
            } else {
                res += 'b'; j++;
            }
        }
        return res;
    }
};

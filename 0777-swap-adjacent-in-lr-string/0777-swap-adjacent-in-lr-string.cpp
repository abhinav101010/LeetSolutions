#include <string>
using namespace std;

class Solution {
public:
    bool canTransform(string start, string end) {
        int n = start.size();
        int i = 0, j = 0;
        while (i < n || j < n) {
            while (i < n && start[i] == 'X') i++;
            while (j < n && end[j] == 'X') j++;
            if (i == n && j == n) break;
            if (i == n || j == n) return false;
            if (start[i] != end[j]) return false;
            if (start[i] == 'L') {
                if (i < j) return false;
            } else { // 'R'
                if (i > j) return false;
            }
            i++;
            j++;
        }
        return true;
    }
};

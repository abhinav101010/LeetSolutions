#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        unordered_map<string, int> seen;
        while (n > 0) {
            string key = "";
            for (int c : cells) key += ('0' + c);
            if (seen.count(key)) {
                int cycle = seen[key] - n;
                n %= cycle;
            } else {
                seen[key] = n;
            }
            if (n == 0) break;
            vector<int> next(8, 0);
            for (int i = 1; i < 7; i++) {
                next[i] = (cells[i-1] == cells[i+1]) ? 1 : 0;
            }
            cells = next;
            n--;
        }
        return cells;
    }
};

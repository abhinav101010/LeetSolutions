#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        unordered_map<int, int> seen;
        while (N > 0) {
            int key = 0;
            for (int i = 0; i < 8; i++) {
                key = (key << 1) | cells[i];
            }
            if (seen.find(key) != seen.end()) {
                int cycle = seen[key] - N;
                N %= cycle;
            } else {
                seen[key] = N;
            }
            if (N == 0) break;
            vector<int> next(8, 0);
            for (int i = 1; i < 7; i++) {
                next[i] = (cells[i-1] == cells[i+1]) ? 1 : 0;
            }
            cells = next;
            N--;
        }
        return cells;
    }
};

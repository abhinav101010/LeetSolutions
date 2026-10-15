#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        vector<int> res;
        if (bound < 1) return res;
        vector<int> xs;
        int xi = 1;
        while (true) {
            xs.push_back(xi);
            if (x == 1) break;
            xi *= x;
            if (xi > bound) break;
        }
        vector<int> ys;
        int yi = 1;
        while (true) {
            ys.push_back(yi);
            if (y == 1) break;
            yi *= y;
            if (yi > bound) break;
        }
        unordered_set<int> set;
        for (int a : xs) {
            for (int b : ys) {
                int s = a + b;
                if (s <= bound) {
                    set.insert(s);
                } else {
                    break;
                }
            }
        }
        res.assign(set.begin(), set.end());
        return res;
    }
};

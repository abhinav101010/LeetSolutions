#include <vector>
#include <deque>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        if (n == 1) {
            vector<int> res(10);
            iota(res.begin(), res.end(), 0);
            return res;
        }
        deque<int> q;
        for (int i = 1; i < 10; i++) {
            q.push_back(i);
        }
        for (int step = 0; step < n-1; step++) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int num = q.front();
                q.pop_front();
                int tail = num % 10;
                vector<int> nexts = {tail + k, tail - k};
                for (int d : nexts) {
                    if (d >= 0 && d <= 9) {
                        q.push_back(num*10 + d);
                    }
                }
            }
        }
        vector<int> res(q.begin(), q.end());
        return res;
    }
};

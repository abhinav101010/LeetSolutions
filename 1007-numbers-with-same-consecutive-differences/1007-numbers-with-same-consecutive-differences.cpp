#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        if (n == 1) {
            vector<int> res(10);
            for (int i = 0; i < 10; i++) res[i] = i;
            return res;
        }
        queue<int> q;
        for (int i = 1; i < 10; i++) {
            q.push(i);
        }
        for (int step = 0; step < n-1; step++) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int num = q.front(); q.pop();
                int tail = num % 10;
                vector<int> next = {tail + k, tail - k};
                for (int d : next) {
                    if (d >= 0 && d <= 9) {
                        q.push(num * 10 + d);
                    }
                }
            }
        }
        vector<int> res;
        while (!q.empty()) {
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
};

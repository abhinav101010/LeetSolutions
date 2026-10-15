#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
        unordered_set<int> res;
        unordered_set<int> cur;
        for (int x : A) {
            unordered_set<int> cur2;
            cur2.insert(x);
            for (int y : cur) {
                cur2.insert(x | y);
            }
            cur.swap(cur2);
            res.insert(cur.begin(), cur.end());
        }
        return (int) res.size();
    }
};

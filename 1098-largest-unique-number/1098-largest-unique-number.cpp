#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int largestUniqueNumber(vector<int>& A) {
        unordered_map<int,int> c;
        for (int x : A) c[x]++;
        int ans = -1;
        for (auto& e : c) if (e.second == 1) ans = max(ans, e.first);
        return ans;
    }
};

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int pathSum(vector<int>& nums) {
        if (nums.empty()) return 0;
        unordered_map<int, unordered_map<int, int>> val;
        for (int num : nums) {
            int d = num / 100;
            int p = (num % 100) / 10;
            int v = num % 10;
            val[d][p] = v;
        }
        return dfs(1, 1, 0, val);
    }

private:
    int dfs(int d, int p, int curSum, unordered_map<int, unordered_map<int, int>>& val) {
        auto it = val.find(d);
        if (it == val.end() || it->second.find(p) == it->second.end()) {
            return 0;
        }
        curSum += it->second[p];
        int leftP = p * 2 - 1;
        int rightP = p * 2;
        auto nextIt = val.find(d + 1);
        bool leftExists = nextIt != val.end() && nextIt->second.find(leftP) != nextIt->second.end();
        bool rightExists = nextIt != val.end() && nextIt->second.find(rightP) != nextIt->second.end();
        if (!leftExists && !rightExists) {
            return curSum;
        }
        int sum = 0;
        if (leftExists) sum += dfs(d + 1, leftP, curSum, val);
        if (rightExists) sum += dfs(d + 1, rightP, curSum, val);
        return sum;
    }
};
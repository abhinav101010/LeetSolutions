class Solution {
public:
    int maxDepth(vector<NestedInteger>& nl) {
        int res = 1;
        for (auto &ni : nl) {
            if (!ni.isInteger()) {
                res = max(res, 1 + maxDepth(ni.getList()));
            }
        }
        return res;
    }
    int dfs(vector<NestedInteger>& nl, int depth) {
        int res = 0;
        for (auto &ni : nl) {
            if (ni.isInteger()) {
                res += ni.getInteger() * depth;
            } else {
                res += dfs(ni.getList(), depth - 1);
            }
        }
        return res;
    }
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        int maxD = maxDepth(nestedList);
        return dfs(nestedList, maxD);
    }
};
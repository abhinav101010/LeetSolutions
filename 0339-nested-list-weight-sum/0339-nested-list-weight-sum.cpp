class Solution {
public:
    int res = 0;
    void dfs(vector<NestedInteger>& nl, int depth) {
        for (auto &ni : nl) {
            if (ni.isInteger()) {
                res += ni.getInteger() * depth;
            } else {
                dfs(ni.getList(), depth + 1);
            }
        }
    }
    int depthSum(vector<NestedInteger>& nestedList) {
        dfs(nestedList, 1);
        return res;
    }
};
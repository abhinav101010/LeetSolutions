import java.util.*;

class Solution {
    private int res = 0;
    public int depthSum(List<NestedInteger> nestedList) {
        dfs(nestedList, 1);
        return res;
    }
    private void dfs(List<NestedInteger> nl, int depth) {
        for (NestedInteger ni : nl) {
            if (ni.isInteger()) {
                res += ni.getInteger() * depth;
            } else {
                dfs(ni.getList(), depth + 1);
            }
        }
    }
}
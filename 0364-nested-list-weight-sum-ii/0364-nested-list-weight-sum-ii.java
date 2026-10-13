import java.util.*;

class Solution {
    private int maxDepth(List<NestedInteger> nl) {
        int res = 1;
        for (NestedInteger ni : nl) {
            if (!ni.isInteger()) {
                res = Math.max(res, 1 + maxDepth(ni.getList()));
            }
        }
        return res;
    }
    private int dfs(List<NestedInteger> nl, int depth) {
        int res = 0;
        for (NestedInteger ni : nl) {
            if (ni.isInteger()) {
                res += ni.getInteger() * depth;
            } else {
                res += dfs(ni.getList(), depth - 1);
            }
        }
        return res;
    }
    public int depthSumInverse(List<NestedInteger> nestedList) {
        int maxD = maxDepth(nestedList);
        return dfs(nestedList, maxD);
    }
}
import java.util.*;

class Solution {
    public List<Boolean> pathExistenceQueries(int n, int[] nums, int maxDiff, int[][] queries) {
        int[] groupId = new int[n];
        int currId = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] - nums[i - 1] > maxDiff) {
                currId++;
            }
            groupId[i] = currId;
        }
        List<Boolean> ans = new ArrayList<>();
        for (int[] q : queries) {
            ans.add(groupId[q[0]] == groupId[q[1]]);
        }
        return ans;
    }
}
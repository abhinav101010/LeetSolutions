class Solution {
    public int arrayNesting(int[] nums) {
        int maxLen = 0;
        boolean[] visited = new boolean[nums.length];
        
        for (int i = 0; i < nums.length; i++) {
            if (!visited[i]) {
                int count = 0;
                int curr = i;
                while (!visited[curr]) {
                    visited[curr] = true;
                    curr = nums[curr];
                    count++;
                }
                maxLen = Math.max(maxLen, count);
            }
        }
        
        return maxLen;
    }
}
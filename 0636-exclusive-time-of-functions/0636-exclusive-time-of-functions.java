import java.util.*;

class Solution {
    public int[] exclusiveTime(int n, List<String> logs) {
        int[] ans = new int[n];
        Stack<Integer> stack = new Stack<>();
        int prevTs = 0;
        
        for (String log : logs) {
            String[] parts = log.split(":");
            int fid = Integer.parseInt(parts[0]);
            String event = parts[1];
            int ts = Integer.parseInt(parts[2]);
            
            if (event.equals("start")) {
                if (!stack.isEmpty()) {
                    ans[stack.peek()] += ts - prevTs;
                }
                stack.push(fid);
                prevTs = ts;
            } else {
                ans[stack.pop()] += ts - prevTs + 1;
                prevTs = ts + 1;
            }
        }
        
        return ans;
    }
}
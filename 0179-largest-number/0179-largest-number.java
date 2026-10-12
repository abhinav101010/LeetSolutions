import java.util.*;

class Solution {
    public String largestNumber(int[] nums) {
        String[] numsStr = new String[nums.length];
        for (int i = 0; i < nums.length; i++) {
            numsStr[i] = String.valueOf(nums[i]);
        }
        
        Arrays.sort(numsStr, (x, y) -> (y + x).compareTo(x + y));
        
        if (numsStr[0].equals("0")) return "0";
        
        StringBuilder sb = new StringBuilder();
        for (String s : numsStr) sb.append(s);
        return sb.toString();
    }
}
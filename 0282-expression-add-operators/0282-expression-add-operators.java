import java.util.*;

class Solution {
    public List<String> addOperators(String num, int target) {
        List<String> result = new ArrayList<>();
        backtrack(num, target, 0, "", 0, 0, result);
        return result;
    }
    
    private void backtrack(String num, int target, int index, String path, long eval, long prev, List<String> result) {
        if (index == num.length()) {
            if (eval == target) {
                result.add(path);
            }
            return;
        }
        
        for (int i = index; i < num.length(); i++) {
            if (i > index && num.charAt(index) == '0') break;
            String currStr = num.substring(index, i + 1);
            long curr = Long.parseLong(currStr);
            
            if (index == 0) {
                backtrack(num, target, i + 1, currStr, curr, curr, result);
            } else {
                backtrack(num, target, i + 1, path + "+" + currStr, eval + curr, curr, result);
                backtrack(num, target, i + 1, path + "-" + currStr, eval - curr, -curr, result);
                backtrack(num, target, i + 1, path + "*" + currStr, eval - prev + prev * curr, prev * curr, result);
            }
        }
    }
}
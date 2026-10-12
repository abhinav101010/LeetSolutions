import java.util.*;

class Solution {
    public boolean isAdditiveNumber(String num) {
        return backtrack(num, 0, new ArrayList<>());
    }
    
    private boolean backtrack(String num, int index, List<Long> path) {
        if (index == num.length()) {
            return path.size() >= 3;
        }
        
        for (int i = index; i < num.length(); i++) {
            if (i > index && num.charAt(index) == '0') break;
            String currStr = num.substring(index, i + 1);
            long curr = Long.parseLong(currStr);
            
            if (path.size() < 2 || curr == path.get(path.size() - 1) + path.get(path.size() - 2)) {
                path.add(curr);
                if (backtrack(num, i + 1, path)) return true;
                path.remove(path.size() - 1);
            }
        }
        
        return false;
    }
}
import java.util.*;

class Solution {
    public boolean makesquare(int[] matchsticks) {
        if (matchsticks.length < 4) return false;
        int total = 0;
        for (int m : matchsticks) total += m;
        if (total % 4 != 0) return false;
        int target = total / 4;
        Arrays.sort(matchsticks);
        reverse(matchsticks);
        if (matchsticks[0] > target) return false;
        
        int[] sides = new int[4];
        return dfs(matchsticks, 0, target, sides);
    }
    
    private boolean dfs(int[] matchsticks, int index, int target, int[] sides) {
        if (index == matchsticks.length) {
            return sides[0] == target && sides[1] == target && sides[2] == target;
        }
        
        for (int i = 0; i < 4; i++) {
            if (sides[i] + matchsticks[index] <= target) {
                sides[i] += matchsticks[index];
                if (dfs(matchsticks, index + 1, target, sides)) return true;
                sides[i] -= matchsticks[index];
            }
            if (sides[i] == 0) break;
        }
        return false;
    }
    
    private void reverse(int[] arr) {
        for (int i = 0, j = arr.length - 1; i < j; i++, j--) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
}
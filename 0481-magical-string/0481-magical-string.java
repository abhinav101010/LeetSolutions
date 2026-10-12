import java.util.*;

class Solution {
    public int magicalString(int n) {
        if (n <= 3) return 1;
        
        List<Integer> s = new ArrayList<>(Arrays.asList(1, 2, 2));
        int i = 2;
        while (s.size() < n) {
            int nextVal = 3 - s.get(s.size() - 1);
            for (int j = 0; j < s.get(i); j++) {
                s.add(nextVal);
            }
            i++;
        }
        
        int count = 0;
        for (int k = 0; k < n; k++) {
            if (s.get(k) == 1) count++;
        }
        return count;
    }
}
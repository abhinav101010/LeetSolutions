import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<Integer> getNoZeroIntegers(int n) {
        for (int a = 1; a < n; a++) {
            int b = n - a;
            if (!containsZero(a) && !containsZero(b)) {
                List<Integer> result = new ArrayList<>();
                result.add(a);
                result.add(b);
                return result;
            }
        }
        return new ArrayList<>();
    }
    
    private boolean containsZero(int num) {
        while (num > 0) {
            if (num % 10 == 0) return true;
            num /= 10;
        }
        return false;
    }
}
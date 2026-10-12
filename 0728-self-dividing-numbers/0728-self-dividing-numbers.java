import java.util.List;
import java.util.ArrayList;

class Solution {
    public List<Integer> selfDividingNumbers(int left, int right) {
        List<Integer> ans = new ArrayList<>();
        for (int num = left; num <= right; num++) {
            if (selfDividing(num)) ans.add(num);
        }
        return ans;
    }

    private boolean selfDividing(int num) {
        for (int n = num; n > 0; n /= 10) {
            int digit = n % 10;
            if (digit == 0 || num % digit != 0) return false;
        }
        return true;
    }
}
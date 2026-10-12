import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<Integer> sumZero(int n) {
        List<Integer> ans = new ArrayList<>();
        for (int i = 1; i <= n / 2; i++) {
            ans.add(i);
            ans.add(-i);
        }
        if (n % 2 == 1) {
            ans.add(0);
        }
        return ans;
    }
}
import java.util.*;
class Solution {
    public List<Integer> addToArrayForm(int[] num, int k) {
        List<Integer> res = new ArrayList<>();
        for (int i = num.length-1; i >= 0; i--) {
            int s = num[i] + k;
            k = s / 10;
            res.add(s % 10);
        }
        while (k > 0) {
            res.add(k % 10);
            k /= 10;
        }
        Collections.reverse(res);
        return res;
    }
}

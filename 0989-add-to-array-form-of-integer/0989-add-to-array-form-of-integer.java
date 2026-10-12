import java.util.*;

class Solution {
    public List<Integer> addToArrayForm(int[] num, int k) {
        LinkedList<Integer> res = new LinkedList<>();
        for (int i = num.length - 1; i >= 0; --i) {
            res.addFirst((num[i] + k) % 10);
            k = (num[i] + k) / 10;
        }
        while (k > 0) {
            res.addFirst(k % 10);
            k /= 10;
        }
        return res;
    }
}

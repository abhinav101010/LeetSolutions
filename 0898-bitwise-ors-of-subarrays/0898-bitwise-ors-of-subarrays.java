import java.util.*;
class Solution {
    public int subarrayBitwiseORs(int[] A) {
        Set<Integer> res = new HashSet<>();
        Set<Integer> cur = new HashSet<>();
        for (int x : A) {
            Set<Integer> cur2 = new HashSet<>();
            cur2.add(x);
            for (int y : cur) {
                cur2.add(x | y);
            }
            cur = cur2;
            res.addAll(cur);
        }
        return res.size();
    }
}

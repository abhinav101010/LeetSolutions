import java.util.*;
class Solution {
    public List<String> commonChars(String[] A) {
        List<String> res = new ArrayList<>();
        for (char c : A[0].toCharArray()) res.add(String.valueOf(c));
        for (int i=1;i<A.length;i++) {
            List<String> newRes = new ArrayList<>();
            for (char c : A[i].toCharArray()) {
                int idx = res.indexOf(String.valueOf(c));
                if (idx != -1) {
                    newRes.add(String.valueOf(c));
                    res.remove(idx);
                }
            }
            res = newRes;
            if (res.isEmpty()) break;
        }
        return res;
    }
}

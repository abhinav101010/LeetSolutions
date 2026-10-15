import java.util.*;
class Solution {
    public int numSpecialEquivGroups(String[] A) {
        Set<String> set = new HashSet<>();
        for (String s : A) {
            StringBuilder even = new StringBuilder();
            StringBuilder odd = new StringBuilder();
            for (int i = 0; i < s.length(); i++) {
                if (i % 2 == 0) {
                    even.append(s.charAt(i));
                } else {
                    odd.append(s.charAt(i));
                }
            }
            char[] e = even.toString().toCharArray();
            char[] o = odd.toString().toCharArray();
            java.util.Arrays.sort(e);
            java.util.Arrays.sort(o);
            set.add(new String(e) + "#" + new String(o));
        }
        return set.size();
    }
}

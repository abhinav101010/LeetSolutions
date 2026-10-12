import java.util.*;

class Solution {
    public boolean hasAllCodes(String s, int k) {
        Set<String> seen = new HashSet<>();
        int need = 1 << k;

        for (int i = 0; i <= s.length() - k; i++) {
            seen.add(s.substring(i, i + k));
            if (seen.size() == need) {
                return true;
            }
        }

        return seen.size() == need;
    }
}

import java.util.*;
class Solution {
    public int expressiveWords(String s, String[] words) {
        List<int[]> sGroups = getGroups(s);
        int ans = 0;
        for (String w : words) {
            List<int[]> wGroups = getGroups(w);
            if (wGroups.size() != sGroups.size()) continue;
            boolean ok = true;
            for (int i = 0; i < sGroups.size(); i++) {
                int[] g1 = wGroups.get(i);
                int[] g2 = sGroups.get(i);
                if (g1[0] != g2[0]) { ok = false; break; }
                if (g1[1] > g2[1]) { ok = false; break; }
                if (g1[1] < g2[1] && g2[1] < 3) { ok = false; break; }
            }
            if (ok) ans++;
        }
        return ans;
    }
    private List<int[]> getGroups(String st) {
        List<int[]> groups = new ArrayList<>();
        int i = 0;
        while (i < st.length()) {
            int j = i;
            while (j < st.length() && st.charAt(j) == st.charAt(i)) {
                j++;
            }
            groups.add(new int[]{st.charAt(i), j - i});
            i = j;
        }
        return groups;
    }
}

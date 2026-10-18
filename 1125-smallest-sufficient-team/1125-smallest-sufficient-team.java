import java.util.*;

class Solution {
    public int[] smallestSufficientTeam(List<String> req_skills, List<List<String>> people) {
        int m = req_skills.size();
        int n = people.size();
        Map<String, Integer> skill_to_idx = new HashMap<>();
        for (int i = 0; i < m; i++) {
            skill_to_idx.put(req_skills.get(i), i);
        }
        int[] p = new int[n];
        for (int i = 0; i < n; i++) {
            for (String s : people.get(i)) {
                p[i] |= 1 << skill_to_idx.get(s);
            }
        }
        int total = 1 << m;
        int[] f = new int[total];
        int[] g = new int[total];
        int[] h = new int[total];
        Arrays.fill(f, n + 1);
        f[0] = 0;
        for (int i = 0; i < total; i++) {
            if (f[i] == n + 1) continue;
            for (int j = 0; j < n; j++) {
                int nxt = i | p[j];
                if (f[i] + 1 < f[nxt]) {
                    f[nxt] = f[i] + 1;
                    g[nxt] = j;
                    h[nxt] = i;
                }
            }
        }
        List<Integer> ans = new ArrayList<>();
        int i = total - 1;
        while (i != 0) {
            ans.add(g[i]);
            i = h[i];
        }
        int[] res = new int[ans.size()];
        for (int k = 0; k < ans.size(); k++) res[k] = ans.get(k);
        return res;
    }
}
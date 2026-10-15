import java.util.*;
class Solution {
    public List<String> subdomainVisits(String[] cpdomains) {
        Map<String, Integer> cnt = new HashMap<>();
        for (String cp : cpdomains) {
            String[] parts = cp.split(" ");
            int count = Integer.parseInt(parts[0]);
            String domain = parts[1];
            String[] dom = domain.split("\\.");
            for (int i = 0; i < dom.length; i++) {
                StringBuilder sb = new StringBuilder();
                for (int j = i; j < dom.length; j++) {
                    if (j > i) sb.append(".");
                    sb.append(dom[j]);
                }
                String sub = sb.toString();
                cnt.put(sub, cnt.getOrDefault(sub, 0) + count);
            }
        }
        List<String> res = new ArrayList<>();
        for (Map.Entry<String, Integer> e : cnt.entrySet()) {
            res.add(e.getValue() + " " + e.getKey());
        }
        return res;
    }
}

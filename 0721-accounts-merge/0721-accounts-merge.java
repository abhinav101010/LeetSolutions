import java.util.*;

class Solution {
    public List<List<String>> accountsMerge(List<List<String>> accounts) {
        int n = accounts.size();
        int[] parent = new int[n];
        for (int i = 0; i < n; i++) parent[i] = i;
        Map<String, Integer> emailToId = new HashMap<>();
        Map<String, String> emailToName = new HashMap<>();
        // find with path compression
        java.util.function.IntFunction<Integer> find = x -> {
            while (parent[x] != x) {
                parent[x] = parent[parent[x]];
                x = parent[x];
            }
            return x;
        };
        // union
        java.util.function.BiConsumer<Integer, Integer> union = (a, b) -> {
            int ra = find.apply(a);
            int rb = find.apply(b);
            if (ra != rb) {
                parent[rb] = ra;
            }
        };
        for (int i = 0; i < n; i++) {
            List<String> acc = accounts.get(i);
            String name = acc.get(0);
            for (int j = 1; j < acc.size(); j++) {
                String email = acc.get(j);
                emailToName.put(email, name);
                if (!emailToId.containsKey(email)) {
                    emailToId.put(email, i);
                } else {
                    union.accept(i, emailToId.get(email));
                }
            }
        }
        Map<Integer, List<String>> groups = new HashMap<>();
        for (Map.Entry<String, Integer> entry : emailToId.entrySet()) {
            String email = entry.getKey();
            int idx = entry.getValue();
            int root = find.apply(idx);
            groups.computeIfAbsent(root, k -> new ArrayList<>()).add(email);
        }
        List<List<String>> res = new ArrayList<>();
        for (List<String> emails : groups.values()) {
            Collections.sort(emails);
            String name = emailToName.get(emails.get(0));
            List<String> entry = new ArrayList<>();
            entry.add(name);
            entry.addAll(emails);
            res.add(entry);
        }
        return res;
    }
}

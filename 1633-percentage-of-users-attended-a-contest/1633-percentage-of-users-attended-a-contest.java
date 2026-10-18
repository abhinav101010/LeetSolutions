import java.util.*;

class User {
    public int user_id;
    public String user_name;
    public User(int user_id, String user_name) { this.user_id = user_id; this.user_name = user_name; }
}

class Register {
    public int contest_id;
    public int user_id;
    public Register(int contest_id, int user_id) { this.contest_id = contest_id; this.user_id = user_id; }
}

class Solution {
    public List<List<String>> percentageAttended(List<User> users, List<Register> reg) {
        int total = users.size();
        TreeMap<Integer, Integer> cnt = new TreeMap<>();
        for (Register r : reg) cnt.merge(r.contest_id, 1, Integer::sum);
        List<Map.Entry<Integer, Double>> rows = new ArrayList<>();
        for (Map.Entry<Integer, Integer> kv : cnt.entrySet()) {
            if (total == 0) continue;
            rows.add(new AbstractMap.SimpleEntry<>(kv.getKey(), kv.getValue() * 100.0 / total));
        }
        rows.sort((a, b) -> {
            int cmp = Double.compare(b.getValue(), a.getValue());
            if (cmp != 0) return cmp;
            return Integer.compare(a.getKey(), b.getKey());
        });
        List<List<String>> result = new ArrayList<>();
        for (Map.Entry<Integer, Double> r : rows)
            result.add(Arrays.asList(String.valueOf(r.getKey()), String.format("%.2f", r.getValue())));
        return result;
    }
}

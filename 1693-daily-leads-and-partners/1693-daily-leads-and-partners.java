import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;

class DailySales {
    String date_id;
    String make_name;
    int lead_id;
    int partner_id;
}

class Solution {
    static class Key {
        String date_id;
        String make_name;
        Key(String d, String m) {
            date_id = d; make_name = m;
        }
        public int hashCode() {
            return (date_id + "|" + make_name).hashCode();
        }
        public boolean equals(Object o) {
            if (!(o instanceof Key)) return false;
            Key k = (Key)o;
            return date_id.equals(k.date_id) && make_name.equals(k.make_name);
        }
    }
    
    public List<List<String>> dailyLeadsAndPartners(List<DailySales> sales) {
        Map<Key, Set<Integer>> leads = new HashMap<>();
        Map<Key, Set<Integer>> partners = new HashMap<>();
        for (DailySales s : sales) {
            Key k = new Key(s.date_id, s.make_name);
            leads.computeIfAbsent(k, x -> new HashSet<>()).add(s.lead_id);
            partners.computeIfAbsent(k, x -> new HashSet<>()).add(s.partner_id);
        }
        List<List<String>> res = new ArrayList<>();
        for (Map.Entry<Key, Set<Integer>> e : leads.entrySet()) {
            Key k = e.getKey();
            List<String> row = new ArrayList<>();
            row.add(k.date_id);
            row.add(k.make_name);
            row.add(String.valueOf(e.getValue().size()));
            row.add(String.valueOf(partners.getOrDefault(k, new HashSet<>()).size()));
            res.add(row);
        }
        Collections.sort(res, (a,b) -> {
            if (!a.get(0).equals(b.get(0))) return a.get(0).compareTo(b.get(0));
            return a.get(1).compareTo(b.get(1));
        });
        return res;
    }
}

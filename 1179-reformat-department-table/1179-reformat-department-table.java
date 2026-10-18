import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class Department {
    int id;
    int revenue;
    String month;
}

class Solution {
    public List<List<String>> reformatTable(List<Department> department) {
        Map<Integer, List<Object[]>> map = new HashMap<>();
        for (Department d : department) {
            map.computeIfAbsent(d.id, k -> new ArrayList<>()).add(new Object[]{d.month, d.revenue});
        }
        String[] months = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", 
                          "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
        List<List<String>> res = new ArrayList<>();
        for (Map.Entry<Integer, List<Object[]>> e : map.entrySet()) {
            Integer id = e.getKey();
            Map<String, Integer> revMap = new HashMap<>();
            for (Object[] it : e.getValue()) {
                revMap.put((String)it[0], (Integer)it[1]);
            }
            List<String> row = new ArrayList<>();
            row.add(String.valueOf(id));
            for (String m : months) {
                if (revMap.containsKey(m)) {
                    row.add(String.valueOf(revMap.get(m)));
                } else {
                    row.add("null");
                }
            }
            res.add(row);
        }
        Collections.sort(res, Comparator.comparingInt(r -> Integer.parseInt(r.get(0))));
        return res;
    }
}

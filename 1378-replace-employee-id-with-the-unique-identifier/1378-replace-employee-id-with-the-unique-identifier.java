import java.util.*;
class Emp { int id; String name; }
class Uni { int id; int unique_id; }
class Solution {
    public List<List<String>> getEmployeeNames(List<Emp> emps, List<Uni> unis) {
        Map<Integer,Integer> m = new HashMap<>();
        for (Uni u : unis) m.put(u.id, u.unique_id);
        List<List<String>> r = new ArrayList<>();
        for (Emp e : emps) {
            String uid = m.containsKey(e.id) ? String.valueOf(m.get(e.id)) : null;
            r.add(Arrays.asList(uid, e.name));
        }
        return r;
    }
}

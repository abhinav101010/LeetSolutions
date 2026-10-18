import java.util.*;
class Emp { int employee_id; int department_id; char primary_flag; }
class Solution {
    public List<int[]> primaryDept(List<Emp> e) {
        Map<Integer,Integer> cnt = new HashMap<>();
        for (Emp x : e) cnt.put(x.employee_id, cnt.getOrDefault(x.employee_id,0)+1);
        Set<String> seen = new HashSet<>();
        List<int[]> r = new ArrayList<>();
        for (Emp x : e) {
            if (x.primary_flag=='Y' || cnt.get(x.employee_id)==1) {
                String k = x.employee_id+"_"+x.department_id;
                if (seen.add(k)) r.add(new int[]{x.employee_id,x.department_id});
            }
        }
        return r;
    }
}

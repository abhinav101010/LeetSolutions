import java.util.*;
class Emp { int id; int month; int salary; }
class Solution {
    public List<int[]> cumulativeSalary(List<Emp> e) {
        Map<Integer,TreeMap<Integer,Integer>> byid = new TreeMap<>();
        for (Emp x : e) byid.computeIfAbsent(x.id,k->new TreeMap<>()).put(x.month,x.salary);
        List<int[]> r = new ArrayList<>();
        for (Map.Entry<Integer,TreeMap<Integer,Integer>> ie : byid.entrySet()) {
            int id = ie.getKey();
            TreeMap<Integer,Integer> months = ie.getValue();
            int maxm = months.lastKey();
            for (int m : months.keySet()) {
                if (m == maxm) continue;
                int sum=0;
                for (int mm : months.keySet()) if (mm<=m && mm>=m-2) sum+=months.get(mm);
                r.add(new int[]{id,m,sum});
            }
        }
        return r;
    }
}

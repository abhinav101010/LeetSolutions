import java.util.*;
class Emp { int id; int salary; Integer managerId; String company; }
class Solution {
    public List<String> companiesBelowAvg(List<Emp> e) {
        Map<String,List<Integer>> all = new HashMap<>();
        for (Emp x : e) all.computeIfAbsent(x.company,k->new ArrayList<>()).add(x.salary);
        List<String> r = new ArrayList<>();
        for (String comp : all.keySet()) {
            Set<Integer> mgrs = new HashSet<>();
            for (Emp x : e) if (x.company.equals(comp) && x.managerId!=null) mgrs.add(x.managerId);
            double ms=0,mc=0;
            for (Emp x : e) if (x.company.equals(comp) && mgrs.contains(x.id)) { ms+=x.salary; mc++; }
            double ca=0; for(int s:all.get(comp)) ca+=s; ca/=all.get(comp).size();
            if (mc>0 && ca < ms/mc) r.add(comp);
        }
        return r;
    }
}

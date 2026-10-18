import java.util.*;
class Act { int machine_id; int process_id; String activity_type; double timestamp; }
class Solution {
    public Map<Integer,Double> avgTime(List<Act> acts) {
        Map<String,double[]> m = new HashMap<>();
        for (Act a : acts) {
            String key = a.machine_id+"_"+a.process_id;
            if (!m.containsKey(key)) m.put(key, new double[2]);
            if (a.activity_type.equals("start")) m.get(key)[0]=a.timestamp;
            else m.get(key)[1]=a.timestamp;
        }
        Map<Integer,List<Double>> bym = new HashMap<>();
        for (Map.Entry<String,double[]> e : m.entrySet()) {
            int mid = Integer.parseInt(e.getKey().split("_")[0]);
            bym.computeIfAbsent(mid,k->new ArrayList<>()).add(e.getValue()[1]-e.getValue()[0]);
        }
        Map<Integer,Double> r = new LinkedHashMap<>();
        for (Map.Entry<Integer,List<Double>> e : bym.entrySet()) {
            double s=0; for(double d:e.getValue()) s+=d;
            r.put(e.getKey(), s/e.getValue().size());
        }
        return r;
    }
}

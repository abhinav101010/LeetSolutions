import java.util.*;

class Activity {
    int machineId;
    int processId;
    String activityType; // start or end
    int timestamp;
    
    public Activity(int machineId, int processId, String activityType, int timestamp) {
        this.machineId = machineId;
        this.processId = processId;
        this.activityType = activityType;
        this.timestamp = timestamp;
    }
}

class Solution {
    public List<Pair> processingTime(List<Activity> activity) {
        Map<String, Integer> startMap = new HashMap<>();
        for (Activity a : activity) {
            if (a.activityType.equals("start")) {
                String key = a.machineId + ":" + a.processId;
                startMap.put(key, a.timestamp);
            }
        }
        Map<Integer, List<Integer>> byMachine = new HashMap<>();
        for (Activity a : activity) {
            if (a.activityType.equals("end")) {
                String key = a.machineId + ":" + a.processId;
                if (startMap.containsKey(key)) {
                    int duration = a.timestamp - startMap.get(key);
                    byMachine.computeIfAbsent(a.machineId, k -> new ArrayList<>()).add(duration);
                }
            }
        }
        List<Pair> res = new ArrayList<>();
        for (Map.Entry<Integer, List<Integer>> e : byMachine.entrySet()) {
            List<Integer> v = e.getValue();
            double sum = 0;
            for (int d : v) sum += d;
            double avg = v.isEmpty() ? 0.0 : sum / v.size();
            avg = Math.round(avg * 1000.0) / 1000.0;
            res.add(new Pair(e.getKey(), avg));
        }
        res.sort(Comparator.comparingInt(p -> p.machineId));
        return res;
    }
    
    static class Pair {
        int machineId;
        double avg;
        public Pair(int machineId, double avg) {
            this.machineId = machineId;
            this.avg = avg;
        }
    }
}

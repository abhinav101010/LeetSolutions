import java.util.*;

class LogSystem {
    private List<Map.Entry<String, Integer>> logs;
    private Map<String, Integer> granularity;

    public LogSystem() {
        logs = new ArrayList<>();
        granularity = new HashMap<>();
        granularity.put("Year", 4);
        granularity.put("Month", 7);
        granularity.put("Day", 10);
        granularity.put("Hour", 13);
        granularity.put("Minute", 16);
        granularity.put("Second", 19);
    }

    public void put(int id, String timestamp) {
        logs.add(new AbstractMap.SimpleEntry<>(timestamp, id));
    }

    public List<Integer> retrieve(String start, String end, String granularity) {
        int g = this.granularity.get(granularity);
        String s = start.substring(0, g);
        String e = end.substring(0, g);
        List<Integer> res = new ArrayList<>();
        for (Map.Entry<String, Integer> entry : logs) {
            String ts = entry.getKey();
            if (s.compareTo(ts.substring(0, g)) <= 0 && ts.substring(0, g).compareTo(e) <= 0) {
                res.add(entry.getValue());
            }
        }
        return res;
    }
}

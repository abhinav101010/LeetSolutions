import java.util.*;
class TimeMap {
    private Map<String, TreeMap<Integer,String>> map;
    public TimeMap() { map = new HashMap<>(); }
    public void set(String key, String value, int timestamp) {
        map.computeIfAbsent(key, k->new TreeMap<>()).put(timestamp, value);
    }
    public String get(String key, int timestamp) {
        TreeMap<Integer,String> tm = map.get(key);
        if (tm == null) return "";
        Integer t = tm.floorKey(timestamp);
        return t==null ? "" : tm.get(t);
    }
}

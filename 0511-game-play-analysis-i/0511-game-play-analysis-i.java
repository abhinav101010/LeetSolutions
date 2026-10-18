import java.util.*;

class Activity {
    public int player_id;
    public int device_id;
    public String event_date;
    public int games_played;
    public Activity(int player_id, int device_id, String event_date, int games_played) {
        this.player_id = player_id; this.device_id = device_id;
        this.event_date = event_date; this.games_played = games_played;
    }
}

class Solution {
    public List<List<String>> gameAnalysis(List<Activity> activity) {
        TreeMap<Integer, String> firstLogin = new TreeMap<>();
        for (Activity a : activity) {
            String cur = firstLogin.get(a.player_id);
            if (cur == null || a.event_date.compareTo(cur) < 0)
                firstLogin.put(a.player_id, a.event_date);
        }
        List<List<String>> result = new ArrayList<>();
        for (Map.Entry<Integer, String> kv : firstLogin.entrySet())
            result.add(Arrays.asList(String.valueOf(kv.getKey()), kv.getValue()));
        return result;
    }
}

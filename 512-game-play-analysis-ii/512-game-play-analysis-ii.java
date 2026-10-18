import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class Activity {
    int player_id;
    int device_id;
    String event_date;
    int games_played;
}

class Solution {
    public List<List<String>> gamePlayAnalysisII(List<Activity> activity) {
        Map<Integer, Activity> first = new HashMap<>();
        for (Activity a : activity) {
            if (!first.containsKey(a.player_id) || 
                a.event_date.compareTo(first.get(a.player_id).event_date) < 0) {
                first.put(a.player_id, a);
            }
        }
        List<List<String>> res = new ArrayList<>();
        for (Map.Entry<Integer, Activity> e : first.entrySet()) {
            List<String> row = new ArrayList<>();
            row.add(String.valueOf(e.getKey()));
            row.add(String.valueOf(e.getValue().device_id));
            res.add(row);
        }
        Collections.sort(res, Comparator.comparingInt(r -> Integer.parseInt(r.get(0))));
        return res;
    }
}

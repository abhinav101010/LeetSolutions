import java.util.*;
class Activity { int player_id; String event_date; int games_played; }
class Solution {
    public List<List<String>> gamesPlayedSoFar(List<Activity> a) {
        a.sort((x,y)-> x.player_id!=y.player_id ? Integer.compare(x.player_id,y.player_id) : x.event_date.compareTo(y.event_date));
        Map<Integer,Integer> running = new HashMap<>();
        List<List<String>> r = new ArrayList<>();
        for (Activity x : a) {
            running.put(x.player_id, running.getOrDefault(x.player_id,0)+x.games_played);
            r.add(Arrays.asList(String.valueOf(x.player_id), x.event_date, String.valueOf(running.get(x.player_id))));
        }
        return r;
    }
}

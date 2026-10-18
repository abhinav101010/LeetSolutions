import java.util.*;

class ActorDirector {
    int actor_id;
    int director_id;
    int timestamp;
    ActorDirector(int actor_id, int director_id, int timestamp) {
        this.actor_id = actor_id; this.director_id = director_id; this.timestamp = timestamp;
    }
}

class Solution {
    public List<List<Integer>> actorsAndDirectors(List<ActorDirector> actorDirector) {
        Map<String, Integer> cnt = new HashMap<>();
        for (ActorDirector a : actorDirector) {
            String key = a.actor_id + "," + a.director_id;
            cnt.put(key, cnt.getOrDefault(key, 0) + 1);
        }
        List<List<Integer>> ans = new ArrayList<>();
        for (Map.Entry<String, Integer> kv : cnt.entrySet()) {
            if (kv.getValue() >= 3) {
                String[] parts = kv.getKey().split(",");
                ans.add(Arrays.asList(Integer.parseInt(parts[0]), Integer.parseInt(parts[1])));
            }
        }
        return ans;
    }
}

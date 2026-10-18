import java.util.*;

class Follower {
    int user_id;
    int follower_id;
    Follower(int user_id, int follower_id) { this.user_id = user_id; this.follower_id = follower_id; }
}

class Solution {
    public List<List<String>> findFollowersCount(List<Follower> followers) {
        Map<Integer, Integer> cnt = new HashMap<>();
        for (Follower f : followers) cnt.put(f.user_id, cnt.getOrDefault(f.user_id, 0) + 1);
        List<List<String>> ans = new ArrayList<>();
        for (Map.Entry<Integer, Integer> kv : cnt.entrySet()) {
            ans.add(Arrays.asList(String.valueOf(kv.getKey()), String.valueOf(kv.getValue())));
        }
        ans.sort((a, b) -> Integer.compare(Integer.parseInt(a.get(0)), Integer.parseInt(b.get(0))));
        return ans;
    }
}

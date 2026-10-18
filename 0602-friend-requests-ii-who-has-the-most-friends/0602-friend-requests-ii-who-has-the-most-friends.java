import java.util.*;

class RequestAccepted {
    int requester_id;
    int accepter_id;
    RequestAccepted(int requester_id, int accepter_id) { this.requester_id = requester_id; this.accepter_id = accepter_id; }
}

class Solution {
    public List<List<String>> mostFriends(List<RequestAccepted> requests) {
        Set<String> s = new HashSet<>();
        for (RequestAccepted r : requests) s.add(r.requester_id + "," + r.accepter_id);
        Map<Integer, Integer> cnt = new HashMap<>();
        for (RequestAccepted r : requests) {
            if (s.contains(r.accepter_id + "," + r.requester_id)) {
                cnt.put(r.requester_id, cnt.getOrDefault(r.requester_id, 0) + 1);
            }
        }
        int bestId = -1, bestNum = -1;
        for (Map.Entry<Integer, Integer> kv : cnt.entrySet()) {
            if (kv.getValue() > bestNum || (kv.getValue() == bestNum && kv.getKey() < bestId)) {
                bestNum = kv.getValue();
                bestId = kv.getKey();
            }
        }
        List<List<String>> ans = new ArrayList<>();
        if (bestId >= 0) ans.add(Arrays.asList(String.valueOf(bestId), String.valueOf(bestNum)));
        return ans;
    }
}

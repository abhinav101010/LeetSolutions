import java.util.*;

class Activity {
    int userId;
    int sessionId;
    String activityDate;
    String activityType;
    public Activity(int userId, int sessionId, String activityDate, String activityType) {
        this.userId = userId;
        this.sessionId = sessionId;
        this.activityDate = activityDate;
        this.activityType = activityType;
    }
}

class Solution {
    public List<Pair> userActivity(List<Activity> activity) {
        TreeMap<String, Set<Integer>> dayUsers = new TreeMap<>();
        for (Activity a : activity) {
            if (a.activityDate.compareTo("2019-06-28") >= 0 && a.activityDate.compareTo("2019-07-27") <= 0) {
                dayUsers.computeIfAbsent(a.activityDate, k -> new HashSet<>()).add(a.userId);
            }
        }
        List<Pair> res = new ArrayList<>();
        for (Map.Entry<String, Set<Integer>> e : dayUsers.entrySet()) {
            res.add(new Pair(e.getKey(), e.getValue().size()));
        }
        return res;
    }
    static class Pair {
        String day;
        int activeUsers;
        public Pair(String day, int activeUsers) {
            this.day = day;
            this.activeUsers = activeUsers;
        }
    }
}

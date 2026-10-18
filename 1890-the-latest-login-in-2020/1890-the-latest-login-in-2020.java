import java.util.*;

class Solution {
    static class Login {
        int user_id;
        String time_stamp;
        
        public Login(int user_id, String time_stamp) {
            this.user_id = user_id;
            this.time_stamp = time_stamp;
        }
    }
    
    static class Result {
        int user_id;
        String last_stamp;
        
        public Result(int user_id, String last_stamp) {
            this.user_id = user_id;
            this.last_stamp = last_stamp;
        }
    }
    
    public List<Result> latestLogin(List<Login> logins) {
        List<Result> result = new ArrayList<>();
        Map<Integer, String> userLatest = new TreeMap<>();
        for (Login l : logins) {
            if (l.time_stamp != null && l.time_stamp.startsWith("2020")) {
                if (!userLatest.containsKey(l.user_id) || l.time_stamp.compareTo(userLatest.get(l.user_id)) > 0) {
                    userLatest.put(l.user_id, l.time_stamp);
                }
            }
        }
        for (Map.Entry<Integer, String> entry : userLatest.entrySet()) {
            result.add(new Result(entry.getKey(), entry.getValue()));
        }
        return result;
    }
}

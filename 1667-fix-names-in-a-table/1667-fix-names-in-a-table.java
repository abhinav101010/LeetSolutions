import java.util.*;

class User {
    int userId;
    String name;
    public User(int userId, String name) {
        this.userId = userId;
        this.name = name;
    }
}

class Solution {
    public List<Pair> fixNames(List<User> users) {
        List<Pair> res = new ArrayList<>();
        for (User u : users) {
            String fixed = u.name;
            if (fixed != null && !fixed.isEmpty()) {
                StringBuilder sb = new StringBuilder(fixed.length());
                sb.append(Character.toUpperCase(fixed.charAt(0)));
                for (int i = 1; i < fixed.length(); i++) {
                    sb.append(Character.toLowerCase(fixed.charAt(i)));
                }
                fixed = sb.toString();
            }
            res.add(new Pair(u.userId, fixed));
        }
        res.sort(Comparator.comparingInt(p -> p.userId));
        return res;
    }
    static class Pair {
        int userId;
        String name;
        public Pair(int userId, String name) {
            this.userId = userId;
            this.name = name;
        }
    }
}

import java.util.*;

class User {
    int id;
    String name;
    public User(int id, String name) {
        this.id = id;
        this.name = name;
    }
}

class Ride {
    int id;
    int userId;
    int distance;
    public Ride(int id, int userId, int distance) {
        this.id = id;
        this.userId = userId;
        this.distance = distance;
    }
}

class Solution {
    public List<Pair> topTravellers(List<User> users, List<Ride> rides) {
        Map<Integer, Integer> dist = new HashMap<>();
        for (Ride r : rides) {
            dist.put(r.userId, dist.getOrDefault(r.userId, 0) + r.distance);
        }
        List<Pair> res = new ArrayList<>();
        for (User u : users) {
            res.add(new Pair(u.name, dist.getOrDefault(u.id, 0)));
        }
        res.sort((a,b) -> {
            if (a.dist != b.dist) return Integer.compare(b.dist, a.dist);
            return a.name.compareTo(b.name);
        });
        return res;
    }
    static class Pair {
        String name;
        int dist;
        public Pair(String name, int dist) {
            this.name = name;
            this.dist = dist;
        }
    }
}

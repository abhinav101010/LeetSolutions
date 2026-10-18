import java.util.*;

class Seat {
    int id;
    boolean free;
    Seat(int id, boolean free) { this.id = id; this.free = free; }
}

class Solution {
    public List<Integer> consecutiveAvailableSeats(List<Seat> seats) {
        Set<Integer> freeIds = new HashSet<>();
        for (Seat s : seats) {
            if (s.free) freeIds.add(s.id);
        }
        List<Integer> ans = new ArrayList<>();
        for (Seat s : seats) {
            if (!s.free) continue;
            if (freeIds.contains(s.id - 1) || freeIds.contains(s.id + 1)) {
                ans.add(s.id);
            }
        }
        Collections.sort(ans);
        return ans;
    }
}

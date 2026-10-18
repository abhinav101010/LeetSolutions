import java.util.*;

class Cinema {
    int seat_id;
    int free;
    Cinema(int seat_id, int free) { this.seat_id = seat_id; this.free = free; }
}

class Solution {
    public List<List<String>> consecutiveAvailableSeats(List<Cinema> cinema) {
        Set<Integer> freeSet = new HashSet<>();
        for (Cinema c : cinema) if (c.free == 1) freeSet.add(c.seat_id);
        List<Integer> seats = new ArrayList<>(freeSet);
        Collections.sort(seats);
        List<List<String>> ans = new ArrayList<>();
        for (int sid : seats) {
            if (freeSet.contains(sid - 1) || freeSet.contains(sid + 1)) {
                ans.add(Arrays.asList(String.valueOf(sid)));
            }
        }
        return ans;
    }
}

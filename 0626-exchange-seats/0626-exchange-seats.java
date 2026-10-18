import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

class Seat {
    int id;
    String student;
}

class Solution {
    static class Pair {
        int id;
        String student;
        Pair(int id, String student) {
            this.id = id;
            this.student = student;
        }
    }
    
    public List<Seat> exchangeSeats(List<Seat> seats) {
        int n = seats.size();
        List<Pair> temp = new ArrayList<>();
        for (int i = 0; i < seats.size(); i++) {
            Seat s = seats.get(i);
            int newId;
            if (s.id % 2 == 1 && s.id != n) {
                newId = s.id + 1;
            } else if (s.id % 2 == 0) {
                newId = s.id - 1;
            } else {
                newId = s.id;
            }
            temp.add(new Pair(newId, s.student));
        }
        Collections.sort(temp, Comparator.comparingInt(p -> p.id));
        List<Seat> result = new ArrayList<>();
        for (Pair p : temp) {
            Seat st = new Seat();
            st.id = p.id;
            st.student = p.student;
            result.add(st);
        }
        return result;
    }
}

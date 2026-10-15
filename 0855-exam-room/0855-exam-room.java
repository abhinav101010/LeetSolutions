import java.util.*;

class ExamRoom {
    private int n;
    private TreeSet<Integer> seats;

    public ExamRoom(int n) {
        this.n = n;
        this.seats = new TreeSet<>();
    }

    public int seat() {
        if (seats.isEmpty()) {
            seats.add(0);
            return 0;
        }
        int pos = 0;
        int maxDist = seats.first(); // distance from start
        Integer prev = null;
        for (int s : seats) {
            if (prev != null) {
                int dist = (s - prev) / 2;
                if (dist > maxDist) {
                    maxDist = dist;
                    pos = prev + dist;
                }
            }
            prev = s;
        }
        int distEnd = n - 1 - seats.last();
        if (distEnd > maxDist) {
            maxDist = distEnd;
            pos = n - 1;
        }
        seats.add(pos);
        return pos;
    }

    public void leave(int p) {
        seats.remove(p);
    }
}

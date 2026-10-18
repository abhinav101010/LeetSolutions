import java.util.*;

class SORTracker {
    private TreeSet<Pair> set;
    private int count;
    static class Pair implements Comparable<Pair> {
        int score;
        String name;
        public Pair(int score, String name) {
            this.score = score;
            this.name = name;
        }
        @Override
        public int compareTo(Pair o) {
            if (this.score != o.score) return Integer.compare(o.score, this.score);
            return this.name.compareTo(o.name);
        }
    }
    public SORTracker() {
        set = new TreeSet<>();
        count = 0;
    }
    public void add(String name, int score) {
        set.add(new Pair(score, name));
    }
    public String get() {
        count++;
        int c = 1;
        for (Pair p : set) {
            if (c == count) return p.name;
            c++;
        }
        return "";
    }
}

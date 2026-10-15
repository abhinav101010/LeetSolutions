import java.util.*;
class TopVotedAce {
    private int[] times;
    private int[] leaders;
    public TopVotedAce(int[] persons, int[] times) {
        this.times = times;
        Map<Integer, Integer> count = new HashMap<>();
        int leader = -1;
        int maxvotes = 0;
        this.leaders = new int[times.length];
        for (int i = 0; i < persons.length; i++) {
            int p = persons[i];
            count.put(p, count.getOrDefault(p, 0) + 1);
            if (count.get(p) >= maxvotes) {
                maxvotes = count.get(p);
                leader = p;
            }
            leaders[i] = leader;
        }
    }
    public int q(int t) {
        int idx = Arrays.binarySearch(times, t);
        if (idx < 0) {
            idx = -idx - 2; // insertion point -1
        }
        return leaders[idx];
    }
}
/**
 * Your TopVotedAce object will be instantiated and called as such:
 * TopVotedAce obj = new TopVotedAce(persons, times);
 * int param_1 = obj.q(t);
 */

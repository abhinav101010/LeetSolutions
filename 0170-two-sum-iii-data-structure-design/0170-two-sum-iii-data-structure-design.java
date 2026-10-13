import java.util.*;

class TwoSum {
    private Map<Integer, Integer> count;
    public TwoSum() {
        count = new HashMap<>();
    }
    public void add(int number) {
        count.put(number, count.getOrDefault(number, 0) + 1);
    }
    public boolean find(int value) {
        for (int num : count.keySet()) {
            int complement = value - num;
            if (count.containsKey(complement)) {
                if (complement != num || count.get(num) > 1) {
                    return true;
                }
            }
        }
        return false;
    }
}
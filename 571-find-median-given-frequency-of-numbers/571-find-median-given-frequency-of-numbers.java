import java.util.*;

class Number {
    int num;
    int frequency;
    Number(int num, int frequency) { this.num = num; this.frequency = frequency; }
}

class Solution {
    public double findMedian(List<Number> numbers) {
        if (numbers.isEmpty()) return 0.0;
        List<Number> ns = new ArrayList<>(numbers);
        ns.sort((a, b) -> Integer.compare(a.num, b.num));
        long total = 0;
        for (Number n : ns) total += n.frequency;
        long low = (total + 1) / 2;
        long high = (total + 2) / 2;
        long cum = 0;
        List<Integer> medians = new ArrayList<>();
        for (Number n : ns) {
            long start = cum + 1;
            cum += n.frequency;
            long end = cum;
            long s = Math.max(start, low);
            long e = Math.min(end, high);
            for (long pos = s; pos <= e; pos++) {
                medians.add(n.num);
            }
        }
        if (medians.isEmpty()) return 0.0;
        double sum = 0.0;
        for (int x : medians) sum += x;
        return sum / (double) medians.size();
    }
}

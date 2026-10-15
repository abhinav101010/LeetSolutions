import java.util.*;

class FreqStack {
    Map<Integer, Integer> freq;
    Map<Integer, Deque<Integer>> group;
    int maxfreq;

    public FreqStack() {
        freq = new HashMap<>();
        group = new HashMap<>();
        maxfreq = 0;
    }

    public void push(int x) {
        int f = freq.getOrDefault(x, 0) + 1;
        freq.put(x, f);
        if (f > maxfreq) {
            maxfreq = f;
        }
        group.computeIfAbsent(f, k -> new ArrayDeque<>()).addLast(x);
    }

    public int pop() {
        int x = group.get(maxfreq).removeLast();
        freq.put(x, freq.get(x) - 1);
        if (group.get(maxfreq).isEmpty()) {
            maxfreq--;
        }
        return x;
    }
}

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack obj = new FreqStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 */

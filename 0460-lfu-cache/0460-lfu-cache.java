import java.util.*;

class LFUCache {
    private int capacity;
    private int minFreq;
    private Map<Integer, Integer> keyToVal;
    private Map<Integer, Integer> keyToFreq;
    private Map<Integer, LinkedHashSet<Integer>> freqToKeys;

    public LFUCache(int capacity) {
        this.capacity = capacity;
        this.minFreq = 0;
        this.keyToVal = new HashMap<>();
        this.keyToFreq = new HashMap<>();
        this.freqToKeys = new HashMap<>();
    }

    public int get(int key) {
        if (!keyToVal.containsKey(key)) return -1;
        updateFreq(key);
        return keyToVal.get(key);
    }

    public void put(int key, int value) {
        if (capacity == 0) return;
        if (keyToVal.containsKey(key)) {
            keyToVal.put(key, value);
            updateFreq(key);
            return;
        }
        
        if (keyToVal.size() >= capacity) {
            int evictKey = freqToKeys.get(minFreq).iterator().next();
            freqToKeys.get(minFreq).remove(evictKey);
            keyToVal.remove(evictKey);
            keyToFreq.remove(evictKey);
        }
        
        keyToVal.put(key, value);
        keyToFreq.put(key, 1);
        freqToKeys.computeIfAbsent(1, k -> new LinkedHashSet<>()).add(key);
        minFreq = 1;
    }

    private void updateFreq(int key) {
        int freq = keyToFreq.get(key);
        freqToKeys.get(freq).remove(key);
        if (freqToKeys.get(freq).isEmpty() && freq == minFreq) {
            minFreq++;
        }
        
        int newFreq = freq + 1;
        keyToFreq.put(key, newFreq);
        freqToKeys.computeIfAbsent(newFreq, k -> new LinkedHashSet<>()).add(key);
    }
}
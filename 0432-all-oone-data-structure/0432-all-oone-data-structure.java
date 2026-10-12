import java.util.*;

class AllOne {
    private Map<String, Integer> keyCount;
    private Map<Integer, Set<String>> countKeys;
    private int minCount;
    private int maxCount;
    
    public AllOne() {
        keyCount = new HashMap<>();
        countKeys = new HashMap<>();
        minCount = 0;
        maxCount = 0;
    }
    
    public void inc(String key) {
        int oldCount = keyCount.getOrDefault(key, 0);
        int newCount = oldCount + 1;
        keyCount.put(key, newCount);
        
        if (oldCount > 0) {
            countKeys.get(oldCount).remove(key);
            if (countKeys.get(oldCount).isEmpty()) {
                countKeys.remove(oldCount);
                if (minCount == oldCount) {
                    minCount = countKeys.isEmpty() ? 0 : Collections.min(countKeys.keySet());
                }
            }
        }
        
        countKeys.computeIfAbsent(newCount, k -> new HashSet<>()).add(key);
        maxCount = Math.max(maxCount, newCount);
        if (minCount == 0 || newCount < minCount) {
            minCount = newCount;
        }
    }
    
    public void dec(String key) {
        if (!keyCount.containsKey(key)) return;
        
        int oldCount = keyCount.get(key);
        int newCount = oldCount - 1;
        
        countKeys.get(oldCount).remove(key);
        if (countKeys.get(oldCount).isEmpty()) {
            countKeys.remove(oldCount);
            if (maxCount == oldCount) {
                maxCount = countKeys.isEmpty() ? 0 : Collections.max(countKeys.keySet());
            }
        }
        
        if (newCount == 0) {
            keyCount.remove(key);
            if (countKeys.isEmpty()) {
                minCount = 0;
            } else {
                minCount = Collections.min(countKeys.keySet());
            }
        } else {
            keyCount.put(key, newCount);
            countKeys.computeIfAbsent(newCount, k -> new HashSet<>()).add(key);
            if (minCount == 0 || newCount < minCount) {
                minCount = newCount;
            }
        }
    }
    
    public String getMaxKey() {
        if (countKeys.isEmpty()) return "";
        return countKeys.get(maxCount).iterator().next();
    }
    
    public String getMinKey() {
        if (countKeys.isEmpty()) return "";
        return countKeys.get(minCount).iterator().next();
    }
}
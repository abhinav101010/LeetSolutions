import java.util.*;

class RandomizedCollection {
    private List<Integer> nums;
    private Map<Integer, Set<Integer>> valToIndices;
    private Random rand;
    
    public RandomizedCollection() {
        nums = new ArrayList<>();
        valToIndices = new HashMap<>();
        rand = new Random();
    }
    
    public boolean insert(int val) {
        valToIndices.computeIfAbsent(val, k -> new HashSet<>()).add(nums.size());
        nums.add(val);
        return valToIndices.get(val).size() == 1;
    }
    
    public boolean remove(int val) {
        if (!valToIndices.containsKey(val) || valToIndices.get(val).isEmpty()) return false;
        
        int idx = valToIndices.get(val).iterator().next();
        valToIndices.get(val).remove(idx);
        int last = nums.get(nums.size() - 1);
        nums.set(idx, last);
        valToIndices.get(last).add(idx);
        valToIndices.get(last).remove(nums.size() - 1);
        nums.remove(nums.size() - 1);
        return true;
    }
    
    public int getRandom() {
        return nums.get(rand.nextInt(nums.size()));
    }
}
import java.util.*;

class Solution {
    private Map<Integer, List<Integer>> valToIndices;
    private Random rand;
    
    public Solution(int[] nums) {
        valToIndices = new HashMap<>();
        rand = new Random();
        for (int i = 0; i < nums.length; i++) {
            valToIndices.computeIfAbsent(nums[i], k -> new ArrayList<>()).add(i);
        }
    }
    
    public int pick(int target) {
        List<Integer> indices = valToIndices.get(target);
        return indices.get(rand.nextInt(indices.size()));
    }
}
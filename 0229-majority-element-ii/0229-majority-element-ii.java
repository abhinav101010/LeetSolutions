class Solution {
    public List<Integer> majorityElement(int[] nums) {
        Map<Integer, Integer> seen = new HashMap<>();
        List<Integer> ans = new ArrayList<>();

        for (int num : nums) {
            seen.put(num, seen.getOrDefault(num, 0) + 1);
        }

        int threshold = nums.length / 3;
        for (Map.Entry<Integer, Integer> entry : seen.entrySet()) {
            if (entry.getValue() > threshold) {
                ans.add(entry.getKey());
            }
        }

        return ans;
    }
}
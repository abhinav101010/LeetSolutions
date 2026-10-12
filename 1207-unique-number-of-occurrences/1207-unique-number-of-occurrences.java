class Solution {
    public boolean uniqueOccurrences(int[] arr) {
        Map<Integer, Integer> count = new HashMap<>();

        for (int num : arr) {
            count.put(num, count.getOrDefault(num, 0) + 1);
        }

        return count.values().size() == new HashSet<>(count.values()).size();
    }
}
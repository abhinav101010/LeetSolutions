class Solution {
    public int removeElement(int[] nums, int val) {
        List<Integer> newList = new ArrayList<>();
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] != val) {
                newList.add(nums[i]);
            }
        }
        for (int i = 0; i < newList.size(); i++) {
            nums[i] = newList.get(i);
        }
        return newList.size();
    }
}
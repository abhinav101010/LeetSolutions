class Solution {
    public boolean checkIfExist(int[] arr) {
        java.util.Set<Integer> seen = new java.util.HashSet<>();
        for (int num : arr) {
            if (seen.contains(num * 2) || (num % 2 == 0 && seen.contains(num / 2))) {
                return true;
            }
            seen.add(num);
        }
        return false;
    }
}
class Solution {
    public boolean makeEqual(String[] words) {
        int[] count = new int[26];
        for (String word : words) {
            for (char ch : word.toCharArray()) {
                count[ch - 'a']++;
            }
        }
        int n = words.length;
        for (int freq : count) {
            if (freq % n != 0) {
                return false;
            }
        }
        return true;
    }
}
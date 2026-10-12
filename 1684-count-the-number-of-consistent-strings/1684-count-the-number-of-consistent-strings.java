class Solution {
    public int countConsistentStrings(String allowed, String[] words) {
        boolean[] ok = new boolean[26];
        for (char c : allowed.toCharArray()) ok[c - 'a'] = true;

        int count = 0;
        for (String w : words) {
            boolean consistent = true;
            for (char c : w.toCharArray()) {
                if (!ok[c - 'a']) {
                    consistent = false;
                    break;
                }
            }
            if (consistent) count++;
        }
        return count;
    }
}
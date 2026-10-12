class Solution {
    public int minOperations(String s) {
        int changes1 = 0;
        int changes2 = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) != (char)('0' + (i % 2))) {
                changes1++;
            }
            if (s.charAt(i) != (char)('0' + (1 - (i % 2)))) {
                changes2++;
            }
        }

        return Math.min(changes1, changes2);
    }
}
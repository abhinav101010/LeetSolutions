class Solution {
    public String shiftingLetters(String s, int[] shifts) {
        int n = s.length();
        long total = 0;
        char[] arr = s.toCharArray();
        for (int i = n - 1; i >= 0; i--) {
            total += shifts[i];
            int shift = (int) (total % 26);
            arr[i] = (char) ((arr[i] - 'a' + shift) % 26 + 'a');
        }
        return new String(arr);
    }
}

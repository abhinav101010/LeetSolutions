class Solution {
    public int[] numberOfLines(int[] widths, String s) {
        int lines = 1;
        int pixels = 0;

        for (char c : s.toCharArray()) {
            int width = widths[c - 'a'];

            if (pixels + width > 100) {
                lines++;
                pixels = width;
            } else {
                pixels += width;
            }
        }

        return new int[]{lines, pixels};
    }
}
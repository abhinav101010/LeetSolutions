class Solution {
    public int[][] flipAndInvertImage(int[][] image) {
        for (int[] row : image) {
            int n = row.length;
            for (int i = 0; i < n / 2; i++) {
                int tmp = row[i];
                row[i] = row[n - 1 - i];
                row[n - 1 - i] = tmp;
            }
            for (int i = 0; i < n; i++) {
                row[i] ^= 1;
            }
        }
        return image;
    }
}
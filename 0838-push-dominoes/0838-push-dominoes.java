class Solution {
    public String pushDominoes(String dominoes) {
        int n = dominoes.length();
        int[] force = new int[n];
        // left to right: R influence
        int f = 0;
        for (int i = 0; i < n; i++) {
            char c = dominoes.charAt(i);
            if (c == 'R') {
                f = n;
            } else if (c == 'L') {
                f = 0;
            } else {
                f = Math.max(f - 1, 0);
            }
            force[i] += f;
        }
        // right to left: L influence
        f = 0;
        for (int i = n - 1; i >= 0; i--) {
            char c = dominoes.charAt(i);
            if (c == 'L') {
                f = n;
            } else if (c == 'R') {
                f = 0;
            } else {
                f = Math.max(f - 1, 0);
            }
            force[i] -= f;
        }
        StringBuilder sb = new StringBuilder();
        for (int fVal : force) {
            if (fVal > 0) sb.append('R');
            else if (fVal < 0) sb.append('L');
            else sb.append('.');
        }
        return sb.toString();
    }
}

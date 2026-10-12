class Solution {
    public String convert(String s, int numRows) {
        if (numRows == 1 || numRows >= s.length()) return s;

        StringBuilder sb = new StringBuilder();
        int step = 2 * (numRows - 1);

        for (int r = 0; r < numRows; r++) {
            for (int i = r; i < s.length(); i += step) {
                sb.append(s.charAt(i));

                if (r > 0 && r < numRows - 1 && i + step - 2 * r < s.length()) {
                    sb.append(s.charAt(i + step - 2 * r));
                }
            }
        }

        return sb.toString();
    }
}

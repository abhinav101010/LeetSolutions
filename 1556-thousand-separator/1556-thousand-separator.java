class Solution {
    public String thousandSeparator(int n) {
        String s = String.valueOf(n);
        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < s.length(); i++) {
            if (i > 0 && (s.length() - i) % 3 == 0) {
                sb.append('.');
            }
            sb.append(s.charAt(i));
        }

        return sb.toString();
    }
}

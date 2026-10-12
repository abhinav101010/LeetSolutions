class Solution {
    public int secondHighest(String s) {
        Set<Integer> digits = new HashSet<>();

        for (char ch : s.toCharArray()) {
            if (Character.isDigit(ch)) {
                digits.add(ch - '0');
            }
        }

        if (digits.size() < 2) {
            return -1;
        }

        int max = Collections.max(digits);
        digits.remove(max);
        return Collections.max(digits);
    }
}
class Solution {
    public int numDifferentIntegers(String word) {
        Set<String> numbers = new HashSet<>();
        StringBuilder current = new StringBuilder();

        for (char ch : word.toCharArray()) {
            if (Character.isDigit(ch)) {
                current.append(ch);
            } else {
                if (!current.isEmpty()) {
                    numbers.add(removeLeadingZeros(current.toString()));
                    current.setLength(0);
                }
            }
        }

        if (!current.isEmpty()) {
            numbers.add(removeLeadingZeros(current.toString()));
        }

        return numbers.size();
    }

    private String removeLeadingZeros(String s) {
        int i = 0;
        while (i < s.length() && s.charAt(i) == '0') {
            i++;
        }
        return i == s.length() ? "0" : s.substring(i);
    }
}
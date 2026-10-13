class Solution {
    public boolean validWordAbbreviation(String word, String abbr) {
        int i = 0, j = 0;
        while (i < word.length() && j < abbr.length()) {
            if (word.charAt(i) == abbr.charAt(j)) {
                i++; j++;
                continue;
            }
            if (!Character.isDigit(abbr.charAt(j)) || abbr.charAt(j) == '0') {
                return false;
            }
            int k = j;
            while (k < abbr.length() && Character.isDigit(abbr.charAt(k))) {
                k++;
            }
            int num = Integer.parseInt(abbr.substring(j, k));
            i += num;
            j = k;
        }
        return i == word.length() && j == abbr.length();
    }
}
class Solution {
    public String reformatNumber(String number) {
        StringBuilder digits = new StringBuilder();
        for (char c : number.toCharArray()) {
            if (c != ' ' && c != '-') digits.append(c);
        }

        int n = digits.length();
        int i = 0;
        StringBuilder ans = new StringBuilder();

        while (n - i > 4) {
            ans.append(digits.substring(i, i + 3)).append('-');
            i += 3;
        }

        int remaining = n - i;
        if (remaining == 4) {
            ans.append(digits.substring(i, i + 2)).append('-');
            ans.append(digits.substring(i + 2, i + 4));
        } else {
            ans.append(digits.substring(i));
        }

        return ans.toString();
    }
}
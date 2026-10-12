class Solution {
    public String modifyString(String s) {
        char[] ch = s.toCharArray();

        for (int i = 0; i < ch.length; i++) {
            if (ch[i] == '?') {
                for (char c = 'a'; c <= 'z'; c++) {
                    if ((i == 0 || ch[i - 1] != c) &&
                        (i == ch.length - 1 || ch[i + 1] != c)) {
                        ch[i] = c;
                        break;
                    }
                }
            }
        }

        return new String(ch);
    }
}

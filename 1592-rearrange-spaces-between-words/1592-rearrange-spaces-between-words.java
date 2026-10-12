class Solution {
    public String reorderSpaces(String text) {
        String[] words = text.trim().split("\\s+");
        int spaces = 0;
        for (char c : text.toCharArray()) {
            if (c == ' ') {
                spaces++;
            }
        }

        if (words.length == 1) {
            return words[0] + " ".repeat(spaces);
        }

        int gap = spaces / (words.length - 1);
        int extra = spaces % (words.length - 1);

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < words.length; i++) {
            if (i > 0) {
                sb.append(" ".repeat(gap));
            }
            sb.append(words[i]);
        }
        sb.append(" ".repeat(extra));

        return sb.toString();
    }
}

class Solution {
    public int scoreOfParentheses(String s) {
        int[] stack = new int[s.length() + 1];
        int ptr = 0;
        stack[ptr] = 0;
        for (char ch : s.toCharArray()) {
            if (ch == '(') {
                ptr++;
                stack[ptr] = 0;
            } else {
                int v = stack[ptr];
                ptr--;
                stack[ptr] += Math.max(2 * v, 1);
            }
        }
        return stack[0];
    }
}

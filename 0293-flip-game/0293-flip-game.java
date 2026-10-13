import java.util.*;

class Solution {
    public List<String> generatePossibleNextMoves(String currentState) {
        List<String> res = new ArrayList<>();
        char[] s = currentState.toCharArray();
        for (int i = 0; i < s.length - 1; i++) {
            if (s[i] == '+' && s[i + 1] == '+') {
                s[i] = '-';
                s[i + 1] = '-';
                res.add(new String(s));
                s[i] = '+';
                s[i + 1] = '+';
            }
        }
        return res;
    }
}
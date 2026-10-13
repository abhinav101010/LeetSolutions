import java.util.*;

class Solution {
    public List<String> generatePalindromes(String s) {
        int[] count = new int[128];
        for (char c : s.toCharArray()) count[c]++;
        List<Character> mid = new ArrayList<>();
        StringBuilder chars = new StringBuilder();
        for (int i = 0; i < 128; i++) {
            if (count[i] % 2 == 1) mid.add((char)i);
            for (int j = 0; j < count[i] / 2; j++) chars.append((char)i);
        }
        if (mid.size() > 1) return new ArrayList<>();
        List<String> res = new ArrayList<>();
        boolean[] used = new boolean[chars.length()];
        char[] path = new char[chars.length()];
        backtrack(chars, used, path, 0, mid, res);
        return res;
    }
    
    private void backtrack(StringBuilder chars, boolean[] used, char[] path, int idx, List<Character> mid, List<String> res) {
        if (idx == chars.length()) {
            StringBuilder half = new StringBuilder(new String(path));
            StringBuilder rev = new StringBuilder(half).reverse();
            String midStr = mid.isEmpty() ? "" : String.valueOf(mid.get(0));
            res.add(half.toString() + midStr + rev.toString());
            return;
        }
        for (int i = 0; i < chars.length(); i++) {
            if (used[i] || (i > 0 && chars.charAt(i) == chars.charAt(i - 1) && !used[i - 1])) continue;
            used[i] = true;
            path[idx] = chars.charAt(i);
            backtrack(chars, used, path, idx + 1, mid, res);
            used[i] = false;
        }
    }
}
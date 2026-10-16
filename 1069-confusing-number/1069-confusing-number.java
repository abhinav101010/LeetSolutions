import java.util.*;
class Solution {
    public boolean confusingNumber(int n) {
        Map<Character,Character> mp = new HashMap<>();
        mp.put('0','0'); mp.put('1','1'); mp.put('6','9'); mp.put('8','8'); mp.put('9','6');
        String s = String.valueOf(n);
        for (char c : s.toCharArray()) if (!mp.containsKey(c)) return false;
        StringBuilder rot = new StringBuilder();
        for (int i = s.length()-1; i >= 0; i--) rot.append(mp.get(s.charAt(i)));
        return !rot.toString().equals(s);
    }
}

import java.util.*;

class Solution {
    public int romanToInt(String s) {
        HashMap<Character, Integer> romInt = new HashMap<>();

        romInt.put('M', 1000);
        romInt.put('D', 500);
        romInt.put('C', 100);
        romInt.put('L', 50);
        romInt.put('X', 10);
        romInt.put('V', 5);
        romInt.put('I', 1);

        int ans = 0;
        int prev = 0;

        for (int i = s.length() - 1; i >= 0; i--) {
            char a = s.charAt(i);
            if (prev > romInt.get(a)) {
                ans -= romInt.get(a);
            } else {
                ans += romInt.get(a);
            }
            prev = romInt.get(a);
        }
        return ans;
    }
}
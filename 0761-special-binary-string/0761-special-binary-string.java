import java.util.*;

class Solution {
    public String makeLargestSpecial(String s) {
        List<String> res = new ArrayList<>();
        int count = 0;
        int i = 0;
        for (int j = 0; j < s.length(); j++) {
            if (s.charAt(j) == '1') {
                count++;
            } else {
                count--;
            }
            if (count == 0) {
                String inner = makeLargestSpecial(s.substring(i+1, j));
                res.add("1" + inner + "0");
                i = j + 1;
            }
        }
        Collections.sort(res, Collections.reverseOrder());
        StringBuilder sb = new StringBuilder();
        for (String str : res) {
            sb.append(str);
        }
        return sb.toString();
    }
}

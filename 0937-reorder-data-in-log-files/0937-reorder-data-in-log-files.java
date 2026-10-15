import java.util.*;
class Solution {
    public String[] reorderLogFiles(String[] logs) {
        List<String> letter = new ArrayList<>();
        List<String> digit = new ArrayList<>();
        for (String log : logs) {
            int space = log.indexOf(' ');
            String id = log.substring(0, space);
            String rest = log.substring(space+1);
            if (Character.isDigit(rest.charAt(0))) {
                digit.add(log);
            } else {
                letter.add(log);
            }
        }
        Collections.sort(letter, (a, b) -> {
            int spaceA = a.indexOf(' ');
            String idA = a.substring(0, spaceA);
            String restA = a.substring(spaceA+1);
            int spaceB = b.indexOf(' ');
            String idB = b.substring(0, spaceB);
            String restB = b.substring(spaceB+1);
            int cmp = restA.compareTo(restB);
            if (cmp != 0) return cmp;
            return idA.compareTo(idB);
        });
        List<String> res = new ArrayList<>(letter);
        res.addAll(digit);
        return res.toArray(new String[0]);
    }
}

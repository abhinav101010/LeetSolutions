import java.util.*;

class Solution {
    public String countOfAtoms(String formula) {
        int[] idx = {0};
        Map<String, Integer> cnt = parseFormula(formula, idx);
        StringBuilder sb = new StringBuilder();
        List<String> names = new ArrayList<>(cnt.keySet());
        Collections.sort(names);
        for (String name : names) {
            sb.append(name);
            int val = cnt.get(name);
            if (val > 1) {
                sb.append(val);
            }
        }
        return sb.toString();
    }
    
    private Map<String, Integer> parseFormula(String formula, int[] idx) {
        Map<String, Integer> cnt = new HashMap<>();
        int n = formula.length();
        while (idx[0] < n && formula.charAt(idx[0]) != ')') {
            if (formula.charAt(idx[0]) == '(') {
                idx[0]++; // skip '('
                Map<String, Integer> inner = parseFormula(formula, idx);
                // parse multiplier
                int start = idx[0];
                while (idx[0] < n && Character.isDigit(formula.charAt(idx[0]))) {
                    idx[0]++;
                }
                int mult = 1;
                if (start < idx[0]) {
                    mult = Integer.parseInt(formula.substring(start, idx[0]));
                }
                for (Map.Entry<String, Integer> entry : inner.entrySet()) {
                    String ch = entry.getKey();
                    int v = entry.getValue();
                    cnt.put(ch, cnt.getOrDefault(ch, 0) + v * mult);
                }
            } else {
                // parse element name
                int start = idx[0];
                idx[0]++; // capital letter
                while (idx[0] < n && Character.isLowerCase(formula.charAt(idx[0]))) {
                    idx[0]++;
                }
                String name = formula.substring(start, idx[0]);
                // parse number
                int startNum = idx[0];
                while (idx[0] < n && Character.isDigit(formula.charAt(idx[0]))) {
                    idx[0]++;
                }
                int num = 1;
                if (startNum < idx[0]) {
                    num = Integer.parseInt(formula.substring(startNum, idx[0]));
                }
                cnt.put(name, cnt.getOrDefault(name, 0) + num);
            }
        }
        // skip ')'
        if (idx[0] < n && formula.charAt(idx[0]) == ')') {
            idx[0]++;
        }
        return cnt;
    }
}

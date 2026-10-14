import java.util.*;

class Solution {
    public int evaluate(String expression) {
        int[] idx = {0};
        List<Map<String, Integer>> scopes = new ArrayList<>();
        return parse(expression, idx, scopes);
    }
    
    private int parse(String s, int[] idx, List<Map<String, Integer>> scopes) {
        if (s.charAt(idx[0]) != '(') {
            // parse atom
            int start = idx[0];
            while (idx[0] < s.length() && s.charAt(idx[0]) != ' ' && s.charAt(idx[0]) != ')') {
                idx[0]++;
            }
            String token = s.substring(start, idx[0]);
            if (Character.isDigit(token.charAt(0)) || token.charAt(0) == '-') {
                return Integer.parseInt(token);
            }
            // variable
            for (int i = scopes.size() - 1; i >= 0; i--) {
                Map<String, Integer> scope = scopes.get(i);
                if (scope.containsKey(token)) {
                    return scope.get(token);
                }
            }
            throw new IllegalArgumentException("Unknown variable: " + token);
        }
        // '('
        idx[0]++; // skip '('
        if (s.startsWith("let", idx[0])) {
            idx[0] += 3; // skip 'let'
            scopes.add(new HashMap<>());
            while (true) {
                // skip spaces
                while (idx[0] < s.length() && s.charAt(idx[0]) == ' ') idx[0]++;
                // check if next is variable or expression
                int start = idx[0];
                // if next char is '(' or digit or '-' or letter, could be variable or expression
                // we need to see if it's a variable (starts with lowercase letter) followed by space then expression
                // Simpler: parse variable name
                int varStart = idx[0];
                while (idx[0] < s.length() && s.charAt(idx[0]) != ' ' && s.charAt(idx[0]) != ')') {
                    idx[0]++;
                }
                String var = s.substring(varStart, idx[0]);
                // skip spaces
                while (idx[0] < s.length() && s.charAt(idx[0]) == ' ') idx[0]++;
                // if next char is ')', then this variable is actually the expression
                if (idx[0] < s.length() && s.charAt(idx[0]) == ')') {
                    int val = parse(s, idx, scopes);
                    scopes.remove(scopes.size()-1);
                    return val;
                }
                // otherwise parse expression for value
                int val = parse(s, idx, scopes);
                scopes.get(scopes.size()-1).put(var, val);
                // skip spaces
                while (idx[0] < s.length() && s.charAt(idx[0]) == ' ') idx[0]++;
            }
        } else if (s.startsWith("add", idx[0])) {
            idx[0] += 3; // skip 'add'
            while (idx[0] < s.length() && s.charAt(idx[0]) == ' ') idx[0]++;
            int a1 = parse(s, idx, scopes);
            while (idx[0] < s.length() && s.charAt(idx[0]) == ' ') idx[0]++;
            int a2 = parse(s, idx, scopes);
            while (idx[0] < s.length() && s.charAt(idx[0]) == ' ') idx[0]++;
            idx[0]++; // skip ')'
            return a1 + a2;
        } else { // mult
            idx[0] += 4; // skip 'mult'
            while (idx[0] < s.length() && s.charAt(idx[0]) == ' ') idx[0]++;
            int a1 = parse(s, idx, scopes);
            while (idx[0] < s.length() && s.charAt(idx[0]) == ' ') idx[0]++;
            int a2 = parse(s, idx, scopes);
            while (idx[0] < s.length() && s.charAt(idx[0]) == ' ') idx[0]++;
            idx[0]++; // skip ')'
            return a1 * a2;
        }
    }
}

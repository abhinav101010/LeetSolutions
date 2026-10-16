import java.util.*;
class Solution {
    public List<String> braceExpansionII(String expression) {
        Set<String> res = new HashSet<>();
        parse(expression, 0, new StringBuilder(), res);
        List<String> list = new ArrayList<>(res);
        Collections.sort(list);
        return list;
    }
    void parse(String expr, int start, StringBuilder prefix, Set<String> res) {
        List<String> cur = new ArrayList<>();
        cur.add("");
        int i = start;
        while (i < expr.length()) {
            char c = expr.charAt(i);
            if (c == '{') {
                int j = i+1, depth = 1;
                while (depth > 0) {
                    if (expr.charAt(j) == '{') depth++;
                    else if (expr.charAt(j) == '}') depth--;
                    j++;
                }
                List<String> inner = new ArrayList<>();
                parseExpr(expr, i+1, j-1, inner);
                List<String> nxt = new ArrayList<>();
                for (String a : cur) for (String b : inner) nxt.add(a+b);
                cur = nxt;
                i = j;
            } else if (c == '}') {
                break;
            } else if (c == ',') {
                break;
            } else {
                for (int k = 0; k < cur.size(); k++) cur.set(k, cur.get(k)+c);
                i++;
            }
        }
        if (cur.size() == 1 && cur.get(0).isEmpty() && start == 0) return;
        for (String s : cur) res.add(prefix.toString()+s);
    }
    void parseExpr(String expr, int start, int end, List<String> out) {
        List<String> cur = new ArrayList<>();
        cur.add("");
        int i = start;
        while (i < end) {
            char c = expr.charAt(i);
            if (c == '{') {
                int j = i+1, depth = 1;
                while (depth > 0) {
                    if (expr.charAt(j) == '{') depth++;
                    else if (expr.charAt(j) == '}') depth--;
                    j++;
                }
                List<String> inner = new ArrayList<>();
                parseExpr(expr, i+1, j-1, inner);
                List<String> nxt = new ArrayList<>();
                for (String a : cur) for (String b : inner) nxt.add(a+b);
                cur = nxt;
                i = j;
            } else if (c == ',') {
                for (String s : cur) out.add(s);
                cur = new ArrayList<>(Collections.singletonList(""));
                i++;
            } else {
                for (int k = 0; k < cur.size(); k++) cur.set(k, cur.get(k)+c);
                i++;
            }
        }
        for (String s : cur) out.add(s);
    }
}

import java.util.*;
import java.util.regex.*;

class Polynomial {
    Map<List<String>, Integer> terms = new HashMap<>();
    
    void normalize() {
        terms.entrySet().removeIf(e -> e.getValue() == 0);
    }
    
    Polynomial add(Polynomial other) {
        Polynomial res = new Polynomial();
        for (Map.Entry<List<String>, Integer> e : this.terms.entrySet()) {
            List<String> k = e.getKey();
            int v = e.getValue();
            res.terms.put(k, res.terms.getOrDefault(k, 0) + v);
        }
        for (Map.Entry<List<String>, Integer> e : other.terms.entrySet()) {
            List<String> k = e.getKey();
            int v = e.getValue();
            res.terms.put(k, res.terms.getOrDefault(k, 0) + v);
        }
        res.normalize();
        return res;
    }
    
    Polynomial sub(Polynomial other) {
        Polynomial res = new Polynomial();
        for (Map.Entry<List<String>, Integer> e : this.terms.entrySet()) {
            List<String> k = e.getKey();
            int v = e.getValue();
            res.terms.put(k, res.terms.getOrDefault(k, 0) + v);
        }
        for (Map.Entry<List<String>, Integer> e : other.terms.entrySet()) {
            List<String> k = e.getKey();
            int v = e.getValue();
            res.terms.put(k, res.terms.getOrDefault(k, 0) - v);
        }
        res.normalize();
        return res;
    }
    
    Polynomial mul(Polynomial other) {
        Polynomial res = new Polynomial();
        for (Map.Entry<List<String>, Integer> e1 : this.terms.entrySet()) {
            List<String> k1 = e1.getKey();
            int v1 = e1.getValue();
            for (Map.Entry<List<String>, Integer> e2 : other.terms.entrySet()) {
                List<String> k2 = e2.getKey();
                int v2 = e2.getValue();
                List<String> vars = new ArrayList<>(k1);
                vars.addAll(k2);
                Collections.sort(vars);
                res.terms.put(vars, res.terms.getOrDefault(vars, 0) + v1 * v2);
            }
        }
        res.normalize();
        return res;
    }
    
    Polynomial constant(int val) {
        terms.put(Collections.emptyList(), terms.getOrDefault(Collections.emptyList(), 0) + val);
        normalize();
        return this;
    }
    
    Polynomial variable(String var) {
        List<String> key = Arrays.asList(var);
        terms.put(key, terms.getOrDefault(key, 0) + 1);
        normalize();
        return this;
    }
    
    List<String> toList() {
        List<List<String>> varsList = new ArrayList<>(terms.keySet());
        varsList.sort((a, b) -> {
            if (a.size() != b.size()) {
                return Integer.compare(b.size(), a.size()); // descending degree
            }
            for (int i = 0; i < a.size(); i++) {
                int cmp = a.get(i).compareTo(b.get(i));
                if (cmp != 0) return cmp;
            }
            return 0;
        });
        List<String> res = new ArrayList<>();
        for (List<String> vars : varsList) {
            int coeff = terms.get(vars);
            if (coeff == 0) continue;
            StringBuilder sb = new StringBuilder();
            sb.append(coeff);
            if (!vars.isEmpty()) {
                sb.append("*");
                for (int i = 0; i < vars.size(); i++) {
                    if (i > 0) sb.append("*");
                    sb.append(vars.get(i));
                }
            }
            res.add(sb.toString());
        }
        return res;
    }
}

class Solution {
    public List<String> basicCalculatorIV(String expression, String[] evalvars, int[] evalints) {
        Map<String, Integer> evalMap = new HashMap<>();
        for (int i = 0; i < evalvars.length; i++) {
            evalMap.put(evalvars[i], evalints[i]);
        }
        // tokenize
        List<String> tokens = new ArrayList<>();
        Matcher m = Pattern.compile("\\d+|[a-z]+|[+\\-*/()]").matcher(expression);
        while (m.find()) {
            tokens.add(m.group());
        }
        Deque<Polynomial> values = new ArrayDeque<>();
        Deque<String> ops = new ArrayDeque<>();
        Map<String, Integer> precedence = new HashMap<>();
        precedence.put("+", 1);
        precedence.put("-", 1);
        precedence.put("*", 2);
        for (String token : tokens) {
            if (Pattern.matches("\\d+", token)) {
                values.addLast(new Polynomial().constant(Integer.parseInt(token)));
            } else if (Pattern.matches("[a-z]+", token)) {
                if (evalMap.containsKey(token)) {
                    values.addLast(new Polynomial().constant(evalMap.get(token)));
                } else {
                    values.addLast(new Polynomial().variable(token));
                }
            } else if (token.equals("(")) {
                ops.addLast(token);
            } else if (token.equals(")")) {
                while (!ops.isEmpty() && !ops.peekLast().equals("(")) {
                    applyOp(values, ops);
                }
                ops.removeLast(); // remove '('
            } else {
                while (!ops.isEmpty() && !ops.peekLast().equals("(") && 
                       precedence.get(ops.peekLast()) >= precedence.get(token)) {
                    applyOp(values, ops);
                }
                ops.addLast(token);
            }
        }
        while (!ops.isEmpty()) {
            applyOp(values, ops);
        }
        return values.isEmpty() ? Collections.emptyList() : values.getLast().toList();
    }
    
    private void applyOp(Deque<Polynomial> values, Deque<String> ops) {
        String op = ops.removeLast();
        Polynomial b = values.removeLast();
        Polynomial a = values.removeLast();
        if (op.equals("+")) {
            values.addLast(a.add(b));
        } else if (op.equals("-")) {
            values.addLast(a.sub(b));
        } else if (op.equals("*")) {
            values.addLast(a.mul(b));
        }
        // no division
    }
}

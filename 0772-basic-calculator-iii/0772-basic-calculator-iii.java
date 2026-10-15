import java.util.Stack;

class Solution {
    public int calculate(String s) {
        Stack<Integer> operands = new Stack<>();
        Stack<Character> operators = new Stack<>();
        java.util.Map<Character, Integer> precedence = java.util.Map.of(
            '+', 1, '-', 1, '*', 2, '/', 2
        );
        int n = s.length();
        int i = 0;
        while (i < n) {
            char ch = s.charAt(i);
            if (ch == ' ') {
                i++;
                continue;
            }
            if (Character.isDigit(ch)) {
                int num = 0;
                while (i < n && Character.isDigit(s.charAt(i))) {
                    num = num * 10 + (s.charAt(i) - '0');
                    i++;
                }
                operands.push(num);
                continue;
            }
            if (ch == '(') {
                operators.push(ch);
            } else if (ch == ')') {
                while (!operators.isEmpty() && operators.peek() != '(') {
                    applyOp(operands, operators);
                }
                operators.pop(); // remove '('
            } else {
                while (!operators.isEmpty() && operators.peek() != '(' && 
                       precedence.get(operators.peek()) >= precedence.get(ch)) {
                    applyOp(operands, operators);
                }
                operators.push(ch);
            }
            i++;
        }
        while (!operators.isEmpty()) {
            applyOp(operands, operators);
        }
        return operands.isEmpty() ? 0 : operands.pop();
    }
    
    private void applyOp(Stack<Integer> operands, Stack<Character> operators) {
        int b = operands.pop();
        int a = operands.pop();
        char op = operators.pop();
        switch (op) {
            case '+': operands.push(a + b); break;
            case '-': operands.push(a - b); break;
            case '*': operands.push(a * b); break;
            case '/': 
                if (a * b < 0) {
                    operands.push(-(Math.abs(a) / Math.abs(b)));
                } else {
                    operands.push(a / b);
                }
                break;
        }
    }
}

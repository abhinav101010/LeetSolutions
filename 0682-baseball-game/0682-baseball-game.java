import java.util.Stack;

class Solution {
    public int calPoints(String[] operations) {
        Stack<Integer> scores = new Stack<>();
        for (String opr : operations) {
            if (opr.equals("C")) {
                scores.pop();
            } else if (opr.equals("D")) {
                scores.push(scores.peek() * 2);
            } else if (opr.equals("+")) {
                int last = scores.pop();
                int prev = scores.peek();
                int sum = last + prev;
                scores.push(last);
                scores.push(sum);
            } else {
                scores.push(Integer.parseInt(opr));
            }
        }
        int total = 0;
        while (!scores.isEmpty()) {
            total += scores.pop();
        }
        return total;
    }
}

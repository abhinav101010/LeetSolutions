import java.util.*;
class Solution {
    public int clumsy(int N) {
        char[] ops = {'*', '/', '+', '-'};
        Deque<Integer> stack = new ArrayDeque<>();
        stack.push(N);
        int op = 1;
        for (int i = N-1; i >= 1; i--) {
            char o = ops[(op-1) % 4];
            if (o == '*') {
                stack.push(stack.pop() * i);
            } else if (o == '/') {
                stack.push(stack.pop() / i);
            } else if (o == '+') {
                stack.push(i);
            } else {
                stack.push(-i);
            }
            op++;
        }
        int res = 0;
        while (!stack.isEmpty()) res += stack.pop();
        return res;
    }
}

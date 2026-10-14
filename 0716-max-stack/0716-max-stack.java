import java.util.*;

class MaxStack {
    private Deque<Integer> stack;
    private Deque<Integer> maxStack;

    public MaxStack() {
        stack = new ArrayDeque<>();
        maxStack = new ArrayDeque<>();
    }

    public void push(int x) {
        stack.push(x);
        if (maxStack.isEmpty() || x >= maxStack.peek()) {
            maxStack.push(x);
        } else {
            maxStack.push(maxStack.peek());
        }
    }

    public int pop() {
        maxStack.pop();
        return stack.pop();
    }

    public int top() {
        return stack.peek();
    }

    public int peekMax() {
        return maxStack.peek();
    }

    public int popMax() {
        int maxVal = maxStack.peek();
        Deque<Integer> buffer = new ArrayDeque<>();
        while (stack.peek() != maxVal) {
            buffer.push(stack.pop());
            maxStack.pop();
        }
        stack.pop(); // pop the max
        maxStack.pop();
        while (!buffer.isEmpty()) {
            push(buffer.pop());
        }
        return maxVal;
    }
}

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack obj = new MaxStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.peekMax();
 * obj.popMax();
 */

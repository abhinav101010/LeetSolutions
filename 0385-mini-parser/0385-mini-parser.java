/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * public interface NestedInteger {
 *     // Constructor initializes an empty nested list.
 *     public NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     public NestedInteger(int value);
 *
 *     // @return true if this NestedInteger holds a single integer, rather than a nested list.
 *     public boolean isInteger();
 *
 *     // @return the single integer that this NestedInteger holds, if it holds a single integer
 *     // Return null if this NestedInteger holds a nested list
 *     public Integer getInteger();
 *
 *     // Set this NestedInteger to hold a single integer.
 *     public void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     public void add(NestedInteger ni);
 *
 *     // @return the nested list that this NestedInteger holds, if it holds a nested list
 *     // Return null if this NestedInteger holds a single integer
 *     public List<NestedInteger> getList();
 * }
 */
import java.util.*;

class Solution {
    public NestedInteger deserialize(String s) {
        if (s.isEmpty() || s.charAt(0) != '[') {
            return new NestedInteger(Integer.parseInt(s));
        }
        
        Deque<NestedInteger> stack = new ArrayDeque<>();
        int num = 0;
        int sign = 1;
        boolean hasNum = false;
        
        for (char c : s.toCharArray()) {
            if (c == '[') {
                stack.push(new NestedInteger());
            } else if (c == ']') {
                if (hasNum) {
                    stack.peek().add(new NestedInteger(sign * num));
                    num = 0;
                    sign = 1;
                    hasNum = false;
                }
                if (stack.size() > 1) {
                    NestedInteger top = stack.pop();
                    stack.peek().add(top);
                }
            } else if (c == ',') {
                if (hasNum) {
                    stack.peek().add(new NestedInteger(sign * num));
                    num = 0;
                    sign = 1;
                    hasNum = false;
                }
            } else if (c == '-') {
                sign = -1;
            } else {
                num = num * 10 + (c - '0');
                hasNum = true;
            }
        }
        
        return stack.peek();
    }
}
import java.util.*;

class Solution {
    public String decodeString(String s) {
        Deque<String> strStack = new ArrayDeque<>();
        Deque<Integer> numStack = new ArrayDeque<>();
        String currStr = "";
        int currNum = 0;
        
        for (char c : s.toCharArray()) {
            if (Character.isDigit(c)) {
                currNum = currNum * 10 + (c - '0');
            } else if (c == '[') {
                strStack.push(currStr);
                numStack.push(currNum);
                currStr = "";
                currNum = 0;
            } else if (c == ']') {
                StringBuilder sb = new StringBuilder(strStack.pop());
                int num = numStack.pop();
                for (int i = 0; i < num; i++) {
                    sb.append(currStr);
                }
                currStr = sb.toString();
            } else {
                currStr += c;
            }
        }
        
        return currStr;
    }
}
import java.util.*;

class Solution {
    public boolean isValid(String code) {
        int n = code.length();
        if (n == 0 || code.charAt(0) != '<') {
            return false;
        }
        Deque<String> stack = new ArrayDeque<>();
        boolean seenTag = false;
        int i = 0;
        while (i < n) {
            if (code.charAt(i) == '<') {
                if (i + 1 >= n) {
                    return false;
                }
                if (code.charAt(i+1) == '!') {
                    // CDATA
                    if (!code.startsWith("<![CDATA[", i)) {
                        return false;
                    }
                    int j = code.indexOf("]]>", i + 9);
                    if (j == -1) {
                        return false;
                    }
                    i = j + 3;
                } else if (code.charAt(i+1) == '/') {
                    // end tag
                    int j = code.indexOf(">", i + 2);
                    if (j == -1) {
                        return false;
                    }
                    String tag = code.substring(i+2, j);
                    if (!isValidTagName(tag)) {
                        return false;
                    }
                    if (stack.isEmpty() || !stack.pop().equals(tag)) {
                        return false;
                    }
                    seenTag = true;
                    if (stack.isEmpty() && j + 1 != n) {
                        return false;
                    }
                    i = j + 1;
                } else {
                    // start tag
                    int j = code.indexOf(">", i + 1);
                    if (j == -1) {
                        return false;
                    }
                    String tag = code.substring(i+1, j);
                    if (!isValidTagName(tag)) {
                        return false;
                    }
                    stack.push(tag);
                    i = j + 1;
                }
            } else {
                i++;
            }
        }
        return stack.isEmpty() && seenTag;
    }
    
    private boolean isValidTagName(String tag) {
        if (tag == null || tag.isEmpty()) {
            return false;
        }
        if (tag.length() < 1 || tag.length() > 9) {
            return false;
        }
        for (char c : tag.toCharArray()) {
            if (!Character.isUpperCase(c)) {
                return false;
            }
        }
        return true;
    }
}

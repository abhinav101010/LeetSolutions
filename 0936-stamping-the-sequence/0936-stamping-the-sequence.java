import java.util.*;
class Solution {
    public int[] movesToStamp(String stamp, String target) {
        int sLen = stamp.length();
        int tLen = target.length();
        char[] tArr = target.toCharArray();
        boolean[] visited = new boolean[tLen];
        List<Integer> res = new ArrayList<>();
        boolean changed;
        do {
            changed = false;
            for (int i = 0; i <= tLen - sLen; i++) {
                if (!visited[i] && canStamp(i, stamp, tArr)) {
                    stampAt(i, stamp, tArr);
                    visited[i] = true;
                    res.add(i);
                    changed = true;
                }
            }
        } while (changed);
        for (char c : tArr) {
            if (c != '*') {
                return new int[0];
            }
        }
        Collections.reverse(res);
        int[] ans = new int[res.size()];
        for (int i = 0; i < res.size(); i++) {
            ans[i] = res.get(i);
        }
        return ans;
    }
    private boolean canStamp(int start, String stamp, char[] arr) {
        boolean changed = false;
        for (int i = 0; i < stamp.length(); i++) {
            if (arr[start+i] == '*') continue;
            if (arr[start+i] != stamp.charAt(i)) return false;
            changed = true;
        }
        return changed;
    }
    private void stampAt(int start, String stamp, char[] arr) {
        for (int i = 0; i < stamp.length(); i++) {
            arr[start+i] = '*';
        }
    }
}

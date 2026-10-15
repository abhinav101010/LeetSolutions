import java.util.*;

class Solution {
    public boolean splitConcat(String[] strs) {
        List<List<String[]>> splits = new ArrayList<>();
        for (String s : strs) {
            List<String[]> cur = new ArrayList<>();
            for (int i = 1; i < s.length(); i++) {
                cur.add(new String[]{s.substring(0, i), s.substring(i)});
            }
            splits.add(cur);
        }
        return backtrack(0, splits, new HashMap<>(), new HashMap<>());
    }
    
    private boolean backtrack(int idx, List<List<String[]>> splits, Map<String,Integer> leftCnt, Map<String,Integer> rightCnt) {
        if (idx == splits.size()) {
            return leftCnt.equals(rightCnt);
        }
        for (String[] pair : splits.get(idx)) {
            String left = pair[0];
            String right = pair[1];
            leftCnt.put(left, leftCnt.getOrDefault(left, 0) + 1);
            rightCnt.put(right, rightCnt.getOrDefault(right, 0) + 1);
            if (backtrack(idx+1, splits, leftCnt, rightCnt)) {
                return true;
            }
            // undo
            leftCnt.put(left, leftCnt.get(left) - 1);
            if (leftCnt.get(left) == 0) {
                leftCnt.remove(left);
            }
            rightCnt.put(right, rightCnt.get(right) - 1);
            if (rightCnt.get(right) == 0) {
                rightCnt.remove(right);
            }
        }
        return false;
    }
}

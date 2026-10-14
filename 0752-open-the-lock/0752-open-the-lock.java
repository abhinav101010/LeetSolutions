import java.util.*;

class Solution {
    public int openLock(String[] deadends, String target) {
        if (target.equals("0000")) return 0;
        Set<String> dead = new HashSet<>(Arrays.asList(deadends));
        if (dead.contains("0000")) return -1;
        Queue<String> q = new LinkedList<>();
        q.offer("0000");
        Set<String> visited = new HashSet<>();
        visited.add("0000");
        int steps = 0;
        while (!q.isEmpty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                String cur = q.poll();
                if (cur.equals(target)) return steps;
                for (String nxt : neighbors(cur)) {
                    if (!dead.contains(nxt) && !visited.contains(nxt)) {
                        visited.add(nxt);
                        q.offer(nxt);
                    }
                }
            }
            steps++;
        }
        return -1;
    }
    
    private List<String> neighbors(String s) {
        List<String> res = new ArrayList<>();
        char[] arr = s.toCharArray();
        for (int i = 0; i < 4; i++) {
            char c = arr[i];
            // turn up
            arr[i] = (c == '9') ? '0' : (char)(c + 1);
            res.add(new String(arr));
            // turn down
            arr[i] = (c == '0') ? '9' : (char)(c - 1);
            res.add(new String(arr));
            // restore
            arr[i] = c;
        }
        return res;
    }
}

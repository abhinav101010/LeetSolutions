import java.util.*;

class Solution {
    public int getMaxRepetitions(String s1, int n1, String s2, int n2) {
        if (n1 == 0) return 0;
        
        int s1Count = 0;
        int s2Count = 0;
        int index = 0;
        Map<Integer, int[]> recall = new HashMap<>();
        
        while (s1Count < n1) {
            s1Count++;
            for (char ch : s1.toCharArray()) {
                if (ch == s2.charAt(index)) {
                    index++;
                    if (index == s2.length()) {
                        s2Count++;
                        index = 0;
                    }
                }
            }
            
            if (recall.containsKey(index)) {
                int[] prev = recall.get(index);
                int preLoopS1 = prev[0];
                int preLoopS2 = prev[1];
                int inLoopS1 = s1Count - preLoopS1;
                int inLoopS2 = s2Count - preLoopS2;
                
                if (inLoopS1 > 0) {
                    int remaining = n1 - preLoopS1;
                    int loops = remaining / inLoopS1;
                    s1Count = preLoopS1 + loops * inLoopS1;
                    s2Count = preLoopS2 + loops * inLoopS2;
                }
            } else {
                recall.put(index, new int[]{s1Count, s2Count});
            }
        }
        
        return s2Count / n2;
    }
}
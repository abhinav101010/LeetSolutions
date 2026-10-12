import java.util.*;

class Solution {
    public String nearestPalindromic(String n) {
        if (n.equals("1")) return "0";
        
        int length = n.length();
        Set<String> candidates = new HashSet<>();
        
        candidates.add(String.valueOf((long)Math.pow(10, length) + 1));
        candidates.add(String.valueOf((long)Math.pow(10, length - 1) - 1));
        
        int prefix = Integer.parseInt(n.substring(0, (length + 1) / 2));
        for (int i : new int[]{prefix - 1, prefix, prefix + 1}) {
            String pal;
            if (length % 2 == 0) {
                pal = i + new StringBuilder(String.valueOf(i)).reverse().toString();
            } else {
                pal = i + new StringBuilder(String.valueOf(i).substring(0, String.valueOf(i).length() - 1)).reverse().toString();
            }
            candidates.add(pal);
        }
        
        candidates.remove(n);
        
        long target = Long.parseLong(n);
        long minDiff = Long.MAX_VALUE;
        String result = "";
        
        for (String cand : candidates) {
            long diff = Math.abs(Long.parseLong(cand) - target);
            if (diff < minDiff || (diff == minDiff && Long.parseLong(cand) < Long.parseLong(result))) {
                minDiff = diff;
                result = cand;
            }
        }
        
        return result;
    }
}
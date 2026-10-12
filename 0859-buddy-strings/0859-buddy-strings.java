class Solution {
    public boolean buddyStrings(String s, String goal) {
        if (s.length() != goal.length()) return false;
        
        if (s.equals(goal)) {
            boolean[] seen = new boolean[26];
            for (char c : s.toCharArray()) {
                if (seen[c - 'a']) return true;
                seen[c - 'a'] = true;
            }
            return false;
        }
        
        int[] diff = new int[2];
        int diffCount = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) != goal.charAt(i)) {
                if (diffCount == 2) return false;
                diff[diffCount++] = i;
            }
        }
        
        if (diffCount != 2) return false;
        
        return s.charAt(diff[0]) == goal.charAt(diff[1]) 
            && s.charAt(diff[1]) == goal.charAt(diff[0]);
    }
}
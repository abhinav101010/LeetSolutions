import java.util.*;

class Solution {
    public List<String> fullJustify(String[] words, int maxWidth) {
        List<String> result = new ArrayList<>();
        int i = 0;
        int n = words.length;
        
        while (i < n) {
            int lineLen = words[i].length();
            int j = i + 1;
            while (j < n && lineLen + 1 + words[j].length() <= maxWidth) {
                lineLen += 1 + words[j].length();
                j++;
            }
            
            int numWords = j - i;
            boolean isLastLine = (j == n);
            
            if (isLastLine || numWords == 1) {
                // Last line or single word: left-justified
                StringBuilder line = new StringBuilder(words[i]);
                for (int k = i + 1; k < j; k++) {
                    line.append(' ').append(words[k]);
                }
                while (line.length() < maxWidth) {
                    line.append(' ');
                }
                result.add(line.toString());
            } else {
                // Fully justified
                int totalSpaces = maxWidth;
                for (int k = i; k < j; k++) {
                    totalSpaces -= words[k].length();
                }
                int spacesBetween = numWords - 1;
                int spacePerGap = totalSpaces / spacesBetween;
                int extraSpaces = totalSpaces % spacesBetween;
                
                StringBuilder line = new StringBuilder(words[i]);
                for (int k = 1; k < numWords; k++) {
                    int spaces = spacePerGap + (k <= extraSpaces ? 1 : 0);
                    for (int s = 0; s < spaces; s++) {
                        line.append(' ');
                    }
                    line.append(words[i + k]);
                }
                result.add(line.toString());
            }
            
            i = j;
        }
        
        return result;
    }
}
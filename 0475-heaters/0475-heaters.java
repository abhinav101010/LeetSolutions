import java.util.*;

class Solution {
    public int findRadius(int[] houses, int[] heaters) {
        Arrays.sort(houses);
        Arrays.sort(heaters);
        int maxRadius = 0;
        int i = 0;
        
        for (int house : houses) {
            while (i < heaters.length - 1 && 
                   Math.abs(heaters[i + 1] - house) <= Math.abs(heaters[i] - house)) {
                i++;
            }
            maxRadius = Math.max(maxRadius, Math.abs(heaters[i] - house));
        }
        
        return maxRadius;
    }
}
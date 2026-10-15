import java.util.HashMap;
import java.util.Map;

class Solution {
    public int totalFruit(int[] fruits) {
        Map<Integer, Integer> count = new HashMap<>();
        int left = 0;
        int max = 0;
        for (int right = 0; right < fruits.length; right++) {
            int fruit = fruits[right];
            count.put(fruit, count.getOrDefault(fruit, 0) + 1);
            while (count.size() > 2) {
                int leftFruit = fruits[left];
                count.put(leftFruit, count.get(leftFruit) - 1);
                if (count.get(leftFruit) == 0) {
                    count.remove(leftFruit);
                }
                left++;
            }
            max = Math.max(max, right - left + 1);
        }
        return max;
    }
}

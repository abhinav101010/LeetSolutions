import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class Solution {
    public String[] findRestaurant(String[] list1, String[] list2) {
        Map<String, Integer> map = new HashMap<String, Integer>();
        for (int i = 0; i < list1.length; i++) {
            map.put(list1[i], i);
        }
        List<String> ans = new ArrayList<String>();
        int leastIndex = Integer.MAX_VALUE;
        for (int i = 0; i < list2.length; i++) {
            if (map.containsKey(list2[i])) {
                int idx = map.get(list2[i]) + i;
                if (idx < leastIndex) {
                    leastIndex = idx;
                    ans.clear();
                    ans.add(list2[i]);
                } else if (idx == leastIndex) {
                    ans.add(list2[i]);
                }
            }
        }
        return ans.toArray(new String[0]);
    }
}
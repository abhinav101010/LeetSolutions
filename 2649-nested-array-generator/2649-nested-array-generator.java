// 2649-nested-array-generator
import java.util.*;

class Solution {
    List<Integer> result = new ArrayList<>();
    
    private void dfs(Object obj) {
        if (obj instanceof Integer) {
            result.add((Integer) obj);
        } else if (obj instanceof List) {
            List<?> list = (List<?>) obj;
            for (Object item : list) {
                dfs(item);
            }
        }
    }
    
    public List<Integer> inorderTraversal(List<Object> arr) {
        result.clear();
        dfs(arr);
        return result;
    }
}

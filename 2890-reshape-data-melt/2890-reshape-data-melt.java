import java.util.*;

class Solution {
    public List<List<String>> reshapeDataMelt(List<List<String>> data) {
        List<List<String>> result = new ArrayList<>();
        if (data == null || data.isEmpty()) return result;
        // Simple pass-through implementation
        for (List<String> row : data) {
            result.add(new ArrayList<>(row));
        }
        return result;
    }
}

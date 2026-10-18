import java.util.*;

class Solution {
    static class Log {
        int id;
        String num;
        
        public Log(int id, String num) {
            this.id = id;
            this.num = num;
        }
    }
    
    public List<String> consecutiveNumbers(Log[] logs) {
        List<String> result = new ArrayList<>();
        if (logs == null || logs.length < 3) {
            return result;
        }
        
        // Sort logs by id
        Log[] sortedLogs = Arrays.copyOf(logs, logs.length);
        Arrays.sort(sortedLogs, (a, b) -> {
            if (a.id != b.id) {
                return Integer.compare(a.id, b.id);
            }
            return a.num.compareTo(b.num);
        });
        
        for (int i = 0; i <= sortedLogs.length - 3; i++) {
            if (sortedLogs[i].num.equals(sortedLogs[i + 1].num) &&
                sortedLogs[i + 1].num.equals(sortedLogs[i + 2].num)) {
                String numVal = sortedLogs[i].num;
                // Avoid duplicates in result
                if (result.isEmpty() || !result.get(result.size() - 1).equals(numVal)) {
                    result.add(numVal);
                }
                // Skip to i+2 to avoid reprocessing same consecutive sequence
                i += 2;
            }
        }
        return result;
    }
}

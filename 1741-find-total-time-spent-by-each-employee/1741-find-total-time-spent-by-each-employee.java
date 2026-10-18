import java.util.*;

class Employee { int empId; String eventDay; int inTime; int outTime; }

class Solution {
    public List<List<String>> findTotalTimeSpentByEachEmployee(List<Employee> employees) {
        Map<String, Integer> total = new TreeMap<>();
        for (Employee e : employees) {
            String key = e.eventDay + "|" + String.valueOf(e.empId);
            total.merge(key, e.outTime - e.inTime, Integer::sum);
        }
        List<List<String>> res = new ArrayList<>();
        for (Map.Entry<String, Integer> kv : total.entrySet()) {
            String key = kv.getKey();
            int pos = key.lastIndexOf('|');
            String day = key.substring(0, pos);
            int empId = Integer.parseInt(key.substring(pos + 1));
            res.add(Arrays.asList(day, String.valueOf(empId), String.valueOf(kv.getValue())));
        }
        return res;
    }
}

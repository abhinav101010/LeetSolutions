import java.util.*;

class Employee {
    public int id;
    public int importance;
    public List<Integer> subordinates;
}

class Solution {
    public int getImportance(List<Employee> employees, int id) {
        Map<Integer, Employee> map = new HashMap<>();
        for (Employee e : employees) {
            map.put(e.id, e);
        }
        int total = 0;
        Deque<Integer> stack = new ArrayDeque<>();
        stack.push(id);
        while (!stack.isEmpty()) {
            int eid = stack.pop();
            Employee e = map.get(eid);
            total += e.importance;
            for (int sub : e.subordinates) {
                stack.push(sub);
            }
        }
        return total;
    }
}

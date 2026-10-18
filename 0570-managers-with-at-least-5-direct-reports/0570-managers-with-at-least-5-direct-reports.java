import java.util.*;

class Solution {
    static class Employee {
        int id;
        String name;
        int managerId; // -1 if no manager
        
        public Employee(int id, String name, int managerId) {
            this.id = id;
            this.name = name;
            this.managerId = managerId;
        }
    }
    
    public List<String> findManagers(List<Employee> employees) {
        List<String> result = new ArrayList<>();
        Map<Integer, Integer> managerCount = new HashMap<>();
        Map<Integer, String> nameMap = new HashMap<>();
        for (Employee e : employees) {
            nameMap.put(e.id, e.name);
            if (e.managerId >= 0) {
                managerCount.put(e.managerId, managerCount.getOrDefault(e.managerId, 0) + 1);
            }
        }
        for (Map.Entry<Integer, Integer> entry : managerCount.entrySet()) {
            if (entry.getValue() >= 5) {
                result.add(nameMap.get(entry.getKey()));
            }
        }
        Collections.sort(result);
        return result;
    }
}

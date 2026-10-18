import java.util.ArrayList;
import java.util.List;

class Employee {
    int id;
    String name;
    int salary;
    int managerId; // 0 or -1 if no manager
}

class Solution {
    public List<String> findEmployees(List<Employee> employees) {
        List<String> result = new ArrayList<>();
        for (int i = 0; i < employees.size(); i++) {
            Employee e = employees.get(i);
            if (e.managerId <= 0) continue;
            for (int j = 0; j < employees.size(); j++) {
                Employee m = employees.get(j);
                if (m.id == e.managerId) {
                    if (e.salary > m.salary) {
                        result.add(e.name);
                    }
                    break;
                }
            }
        }
        return result;
    }
}

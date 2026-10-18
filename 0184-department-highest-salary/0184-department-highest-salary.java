import java.util.*;

class Employee { int id; String name; int salary; int departmentId; }
class Department { int id; String name; }

class Solution {
    public List<List<String>> departmentHighestSalary(List<Employee> employees, List<Department> departments) {
        Map<Integer, String> deptName = new HashMap<>();
        for (Department d : departments) deptName.put(d.id, d.name);
        Map<Integer, Integer> maxSal = new HashMap<>();
        for (Employee e : employees) {
            Integer cur = maxSal.get(e.departmentId);
            if (cur == null || e.salary > cur) maxSal.put(e.departmentId, e.salary);
        }
        List<List<String>> res = new ArrayList<>();
        for (Employee e : employees) {
            if (!deptName.containsKey(e.departmentId)) continue;
            Integer ms = maxSal.get(e.departmentId);
            if (ms != null && e.salary == ms) {
                res.add(Arrays.asList(deptName.get(e.departmentId), e.name, String.valueOf(e.salary)));
            }
        }
        return res;
    }
}

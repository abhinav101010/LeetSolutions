import java.util.*;

class Employee {
    public int id;
    public int salary;
    public Employee(int id, int salary) { this.id = id; this.salary = salary; }
}

class Solution {
    public List<List<String>> secondHighestSalary(List<Employee> employees) {
        TreeSet<Integer> distinct = new TreeSet<>();
        for (Employee e : employees) distinct.add(e.salary);
        List<List<String>> result = new ArrayList<>();
        if (distinct.size() < 2) {
            result.add(Arrays.asList("NULL"));
            return result;
        }
        int i = 0;
        Integer second = null;
        for (Integer v : distinct.descendingSet()) {
            if (i++ == 1) { second = v; break; }
        }
        result.add(Arrays.asList(String.valueOf(second)));
        return result;
    }
}

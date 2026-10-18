import java.util.*;

class Employee { int id; int salary; }

class Solution {
    public Integer getNthHighestSalary(List<Employee> employees, int N) {
        TreeSet<Integer> set = new TreeSet<>(Collections.reverseOrder());
        for (Employee e : employees) set.add(e.salary);
        int i = 1;
        for (int s : set) {
            if (i == N) return s;
            i++;
        }
        return null;
    }
}

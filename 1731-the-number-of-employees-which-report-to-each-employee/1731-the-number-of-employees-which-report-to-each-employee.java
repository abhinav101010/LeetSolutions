import java.util.*;

class Employee {
    int employee_id;
    String name;
    Integer reports_to;
    int age;
    Employee(int employee_id, String name, Integer reports_to, int age) {
        this.employee_id = employee_id; this.name = name; this.reports_to = reports_to; this.age = age;
    }
}

class Report {
    int employee_id;
    String name;
    int reports_count;
    int average_age;
    Report(int employee_id, String name, int reports_count, int average_age) {
        this.employee_id = employee_id; this.name = name; this.reports_count = reports_count; this.average_age = average_age;
    }
}

class Solution {
    public List<Report> countEmployees(List<Employee> employees) {
        Map<Integer, Integer> cnt = new HashMap<>();
        Map<Integer, Long> sumAge = new HashMap<>();
        for (Employee e : employees) {
            if (e.reports_to != null) {
                int m = e.reports_to;
                cnt.put(m, cnt.getOrDefault(m, 0) + 1);
                sumAge.put(m, sumAge.getOrDefault(m, 0L) + e.age);
            }
        }
        List<Report> ans = new ArrayList<>();
        for (Employee e : employees) {
            Integer c = cnt.get(e.employee_id);
            if (c != null && c >= 1) {
                int avg = (int) Math.round((double) sumAge.get(e.employee_id) / (double) c);
                ans.add(new Report(e.employee_id, e.name, c, avg));
            }
        }
        ans.sort((a, b) -> Integer.compare(a.employee_id, b.employee_id));
        return ans;
    }
}

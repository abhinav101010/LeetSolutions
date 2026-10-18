import java.util.*;

class Employee {
    int Id;
    int Month;
    int Salary;
    Employee(int Id, int Month, int Salary) { this.Id = Id; this.Month = Month; this.Salary = Salary; }
}

class Solution {
    public List<List<String>> cumulativeSalary(List<Employee> employees) {
        Map<Integer, List<Employee>> byId = new HashMap<>();
        for (Employee e : employees) byId.computeIfAbsent(e.Id, k -> new ArrayList<>()).add(e);
        List<List<String>> ans = new ArrayList<>();
        for (Map.Entry<Integer, List<Employee>> kv : byId.entrySet()) {
            int id = kv.getKey();
            List<Employee> rows = kv.getValue();
            rows.sort((a, b) -> Integer.compare(a.Month, b.Month));
            int maxMonth = rows.get(rows.size() - 1).Month;
            int n = rows.size();
            for (int i = 0; i < n; i++) {
                int sum = rows.get(i).Salary;
                if (i - 1 >= 0) sum += rows.get(i - 1).Salary;
                if (i - 2 >= 0) sum += rows.get(i - 2).Salary;
                if (rows.get(i).Month == maxMonth) sum -= rows.get(i).Salary;
                ans.add(Arrays.asList(String.valueOf(id), String.valueOf(rows.get(i).Month), String.valueOf(sum)));
            }
        }
        ans.sort((a, b) -> {
            int c = Integer.compare(Integer.parseInt(a.get(0)), Integer.parseInt(b.get(0)));
            if (c != 0) return c;
            return Integer.compare(Integer.parseInt(a.get(1)), Integer.parseInt(b.get(1)));
        });
        return ans;
    }
}

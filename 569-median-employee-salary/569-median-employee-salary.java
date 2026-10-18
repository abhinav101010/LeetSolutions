import java.util.*;

class Employee {
    int Id;
    int Company;
    int Salary;
    Employee(int Id, int Company, int Salary) { this.Id = Id; this.Company = Company; this.Salary = Salary; }
}

class Solution {
    public List<List<String>> medianEmployeeSalary(List<Employee> employees) {
        Map<Integer, List<Employee>> byComp = new HashMap<>();
        for (Employee e : employees) byComp.computeIfAbsent(e.Company, k -> new ArrayList<>()).add(e);
        List<List<String>> ans = new ArrayList<>();
        for (Map.Entry<Integer, List<Employee>> kv : byComp.entrySet()) {
            int comp = kv.getKey();
            List<Employee> rows = kv.getValue();
            int n = rows.size();
            List<Integer> ascIdx = new ArrayList<>(), descIdx = new ArrayList<>();
            for (int i = 0; i < n; i++) { ascIdx.add(i); descIdx.add(i); }
            ascIdx.sort((a, b) -> {
                if (rows.get(a).Salary != rows.get(b).Salary) return Integer.compare(rows.get(a).Salary, rows.get(b).Salary);
                return Integer.compare(a, b);
            });
            descIdx.sort((a, b) -> {
                if (rows.get(a).Salary != rows.get(b).Salary) return Integer.compare(rows.get(b).Salary, rows.get(a).Salary);
                return Integer.compare(a, b);
            });
            int[] rnAsc = new int[n], rnDesc = new int[n];
            for (int i = 0; i < n; i++) {
                rnAsc[ascIdx.get(i)] = i + 1;
                rnDesc[descIdx.get(i)] = i + 1;
            }
            for (int i = 0; i < n; i++) {
                int ra = rnAsc[i], rd = rnDesc[i];
                if (ra == rd || ra == rd - 1 || ra == rd + 1) {
                    ans.add(Arrays.asList(String.valueOf(rows.get(i).Id), String.valueOf(comp), String.valueOf(rows.get(i).Salary)));
                }
            }
        }
        ans.sort((a, b) -> {
            int c = Integer.compare(Integer.parseInt(a.get(1)), Integer.parseInt(b.get(1)));
            if (c != 0) return c;
            return Integer.compare(Integer.parseInt(a.get(0)), Integer.parseInt(b.get(0)));
        });
        return ans;
    }
}

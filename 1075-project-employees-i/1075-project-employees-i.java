import java.util.*;

class Project {
    public int project_id;
    public int employee_id;
    public Project(int project_id, int employee_id) { this.project_id = project_id; this.employee_id = employee_id; }
}

class Employee {
    public int employee_id;
    public String name;
    public int experience_years;
    public Employee(int employee_id, String name, int experience_years) {
        this.employee_id = employee_id; this.name = name; this.experience_years = experience_years;
    }
}

class Solution {
    public List<List<String>> projectEmployees(List<Project> projects, List<Employee> employees) {
        HashMap<Integer, Integer> empExp = new HashMap<>();
        for (Employee e : employees) empExp.put(e.employee_id, e.experience_years);
        TreeMap<Integer, double[]> proj = new TreeMap<>();
        for (Project p : projects) {
            Integer ex = empExp.get(p.employee_id);
            if (ex == null) continue;
            double[] d = proj.computeIfAbsent(p.project_id, k -> new double[2]);
            d[0] += ex;
            d[1] += 1;
        }
        List<List<String>> result = new ArrayList<>();
        for (Map.Entry<Integer, double[]> kv : proj.entrySet()) {
            double avg = kv.getValue()[0] / kv.getValue()[1];
            result.add(Arrays.asList(String.valueOf(kv.getKey()), String.format("%.2f", avg)));
        }
        return result;
    }
}

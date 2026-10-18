import java.util.*;

class Department {
    int id;
    String name;
    public Department(int id, String name) {
        this.id = id;
        this.name = name;
    }
}

class Student {
    int id;
    String name;
    int departmentId;
    public Student(int id, String name, int departmentId) {
        this.id = id;
        this.name = name;
        this.departmentId = departmentId;
    }
}

class Solution {
    public List<Pair> countStudents(List<Department> departments, List<Student> students) {
        Map<Integer, Integer> cnt = new HashMap<>();
        for (Student s : students) {
            cnt.put(s.departmentId, cnt.getOrDefault(s.departmentId, 0) + 1);
        }
        List<Pair> res = new ArrayList<>();
        for (Department d : departments) {
            res.add(new Pair(d.name, cnt.getOrDefault(d.id, 0)));
        }
        res.sort((a,b) -> {
            if (a.count != b.count) return Integer.compare(b.count, a.count);
            return a.deptName.compareTo(b.deptName);
        });
        return res;
    }
    static class Pair {
        String deptName;
        int count;
        public Pair(String deptName, int count) {
            this.deptName = deptName;
            this.count = count;
        }
    }
}

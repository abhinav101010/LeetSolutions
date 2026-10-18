import java.util.*;

class Course {
    String student;
    String className;
    public Course(String student, String className) {
        this.student = student;
        this.className = className;
    }
}

class Solution {
    public List<String> findClasses(List<Course> courses) {
        Map<String, Integer> cnt = new HashMap<>();
        for (Course c : courses) {
            cnt.put(c.className, cnt.getOrDefault(c.className, 0) + 1);
        }
        List<String> res = new ArrayList<>();
        for (Map.Entry<String, Integer> e : cnt.entrySet()) {
            if (e.getValue() >= 5) {
                res.add(e.getKey());
            }
        }
        Collections.sort(res);
        return res;
    }
}

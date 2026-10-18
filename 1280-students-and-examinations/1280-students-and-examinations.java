import java.util.*;

class Student { int studentId; String studentName; }
class Subject { String subjectName; }
class Examination { int studentId; String subjectName; }

class Solution {
    public List<List<String>> studentsAndExaminations(List<Student> students, List<Subject> subjects, List<Examination> examinations) {
        Map<String, Integer> examCount = new HashMap<>();
        for (Examination e : examinations) {
            String key = String.valueOf(e.studentId) + "|" + e.subjectName;
            examCount.merge(key, 1, Integer::sum);
        }
        List<List<String>> res = new ArrayList<>();
        for (Student s : students) {
            for (Subject sub : subjects) {
                String key = String.valueOf(s.studentId) + "|" + sub.subjectName;
                Integer cnt = examCount.get(key);
                if (cnt == null) cnt = 0;
                res.add(Arrays.asList(String.valueOf(s.studentId), s.studentName, sub.subjectName, String.valueOf(cnt)));
            }
        }
        res.sort((a, b) -> {
            int ai = Integer.parseInt(a.get(0)), bi = Integer.parseInt(b.get(0));
            if (ai != bi) return ai - bi;
            return a.get(2).compareTo(b.get(2));
        });
        return res;
    }
}

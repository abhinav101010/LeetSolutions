import java.util.*;

class Student {
    String name;
    String continent;
    public Student(String name, String continent) {
        this.name = name;
        this.continent = continent;
    }
}

class Solution {
    public List<String[]> report(List<Student> students) {
        List<String> america = new ArrayList<>();
        List<String> asia = new ArrayList<>();
        List<String> europe = new ArrayList<>();
        for (Student s : students) {
            if ("America".equals(s.continent)) america.add(s.name);
            else if ("Asia".equals(s.continent)) asia.add(s.name);
            else if ("Europe".equals(s.continent)) europe.add(s.name);
        }
        Collections.sort(america);
        Collections.sort(asia);
        Collections.sort(europe);
        int maxn = Math.max(america.size(), Math.max(asia.size(), europe.size()));
        List<String[]> res = new ArrayList<>();
        for (int i = 0; i < maxn; i++) {
            String a = i < america.size() ? america.get(i) : "";
            String as = i < asia.size() ? asia.get(i) : "";
            String e = i < europe.size() ? europe.get(i) : "";
            res.add(new String[]{a, as, e});
        }
        return res;
    }
}

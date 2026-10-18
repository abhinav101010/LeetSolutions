import java.util.*;

class Salary {
    int id;
    String name;
    String sex;
    int salary;
    Salary(int id, String name, String sex, int salary) { this.id = id; this.name = name; this.sex = sex; this.salary = salary; }
}

class Solution {
    public List<List<String>> swapSex(List<Salary> salaries) {
        List<List<String>> ans = new ArrayList<>();
        for (Salary s : salaries) {
            String sex = s.sex;
            if (sex.equals("m")) sex = "f";
            else if (sex.equals("f")) sex = "m";
            ans.add(Arrays.asList(String.valueOf(s.id), s.name, sex, String.valueOf(s.salary)));
        }
        ans.sort((a, b) -> Integer.compare(Integer.parseInt(a.get(0)), Integer.parseInt(b.get(0))));
        return ans;
    }
}

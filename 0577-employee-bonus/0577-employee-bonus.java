import java.util.ArrayList;
import java.util.List;

class Employee {
    int empId;
    String name;
    int supervisor;
    int salary;
}

class Bonus {
    int empId;
    int bonus;
}

class Solution {
    public List<List<String>> employeeBonus(List<Employee> employees, List<Bonus> bonusList) {
        List<List<String>> result = new ArrayList<>();
        for (int i = 0; i < employees.size(); i++) {
            Employee e = employees.get(i);
            boolean found = false;
            int bonusVal = 0;
            for (int j = 0; j < bonusList.size(); j++) {
                Bonus b = bonusList.get(j);
                if (b.empId == e.empId) {
                    found = true;
                    bonusVal = b.bonus;
                    break;
                }
            }
            if (!found || bonusVal < 1000) {
                List<String> row = new ArrayList<>();
                row.add(e.name);
                if (!found) {
                    row.add("null");
                } else {
                    row.add(String.valueOf(bonusVal));
                }
                result.add(row);
            }
        }
        return result;
    }
}

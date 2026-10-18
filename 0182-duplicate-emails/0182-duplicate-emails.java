import java.util.*;

class Person {
    int id;
    String email;
    Person(int id, String email) { this.id = id; this.email = email; }
}

class Solution {
    public List<List<String>> duplicateEmails(List<Person> persons) {
        Map<String, Integer> cnt = new HashMap<>();
        for (Person p : persons) cnt.put(p.email, cnt.getOrDefault(p.email, 0) + 1);
        List<List<String>> ans = new ArrayList<>();
        for (Map.Entry<String, Integer> kv : cnt.entrySet()) {
            if (kv.getValue() > 1) ans.add(Arrays.asList(kv.getKey()));
        }
        return ans;
    }
}

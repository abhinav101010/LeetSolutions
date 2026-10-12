import java.util.*;

class Solution {
    public int numUniqueEmails(String[] emails) {
        Set<String> unique = new HashSet<>();
        for (String email : emails) {
            String[] parts = email.split("@");
            String local = parts[0].split("\\+")[0].replace(".", "");
            unique.add(local + "@" + parts[1]);
        }
        return unique.size();
    }
}
import java.util.ArrayList;
import java.util.List;
import java.util.regex.Pattern;

class User {
    int user_id;
    String name;
    String mail;
}

class Solution {
    public List<User> findUsers(List<User> users) {
        List<User> res = new ArrayList<>();
        Pattern p = Pattern.compile("^[A-Za-z][A-Za-z0-9_.-]*@leetcode\\.com$");
        for (User u : users) {
            if (p.matcher(u.mail).matches()) {
                res.add(u);
            }
        }
        return res;
    }
}

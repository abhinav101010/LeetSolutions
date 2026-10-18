import java.util.*;

class Customer {
    int id;
    String name;
    Integer referee_id;
    Customer(int id, String name, Integer referee_id) {
        this.id = id; this.name = name; this.referee_id = referee_id;
    }
}

class Solution {
    public List<String> findCustomerReferee(List<Customer> customers) {
        List<String> ans = new ArrayList<>();
        for (Customer c : customers) {
            if (c.referee_id == null || c.referee_id != 2) {
                ans.add(c.name);
            }
        }
        return ans;
    }
}

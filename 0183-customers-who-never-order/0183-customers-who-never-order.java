import java.util.*;

class Customer {
    int id;
    String name;
    Customer(int id, String name) { this.id = id; this.name = name; }
}

class Order {
    int id;
    int customerId;
    Order(int id, int customerId) { this.id = id; this.customerId = customerId; }
}

class Solution {
    public List<String> customersWhoNeverOrder(List<Customer> customers, List<Order> orders) {
        Set<Integer> orderedIds = new HashSet<>();
        for (Order o : orders) orderedIds.add(o.customerId);
        List<String> ans = new ArrayList<>();
        for (Customer c : customers) {
            if (!orderedIds.contains(c.id)) ans.add(c.name);
        }
        return ans;
    }
}

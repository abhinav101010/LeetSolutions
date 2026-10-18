import java.util.*;

class SalesPerson { int salesId; String name; int salary; int commissionRate; String hireDate; }
class Company { int comId; String name; String city; }
class Order { int orderId; String date; int comId; int salesId; int amount; }

class Solution {
    public List<String> salesPerson(List<SalesPerson> salesPersons, List<Company> companies, List<Order> orders) {
        Set<Integer> redComIds = new HashSet<>();
        for (Company c : companies) if ("RED".equals(c.name)) redComIds.add(c.comId);
        Set<Integer> badSalesIds = new HashSet<>();
        for (Order o : orders) if (redComIds.contains(o.comId)) badSalesIds.add(o.salesId);
        List<String> res = new ArrayList<>();
        for (SalesPerson s : salesPersons) if (!badSalesIds.contains(s.salesId)) res.add(s.name);
        return res;
    }
}

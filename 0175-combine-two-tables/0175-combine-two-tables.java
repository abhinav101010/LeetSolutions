import java.util.*;

class Person { int personId; String lastName; String firstName; }
class Address { int addressId; int personId; String city; String state; }

class Solution {
    public List<List<String>> combineTwoTables(List<Person> persons, List<Address> addresses) {
        Map<Integer, Address> addrMap = new HashMap<>();
        for (Address a : addresses) addrMap.put(a.personId, a);
        List<List<String>> res = new ArrayList<>();
        for (Person p : persons) {
            List<String> row = new ArrayList<>(Arrays.asList(p.firstName, p.lastName));
            Address a = addrMap.get(p.personId);
            if (a != null) { row.add(a.city); row.add(a.state); }
            else { row.add(null); row.add(null); }
            res.add(row);
        }
        return res;
    }
}

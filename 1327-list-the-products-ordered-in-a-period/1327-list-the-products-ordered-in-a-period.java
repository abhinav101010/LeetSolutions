import java.util.*;

class Product {
    public int product_id;
    public String product_name;
    public String product_category;
    public Product(int product_id, String product_name, String product_category) {
        this.product_id = product_id; this.product_name = product_name; this.product_category = product_category;
    }
}

class Order {
    public int product_id;
    public String order_date;
    public int unit;
    public Order(int product_id, String order_date, int unit) {
        this.product_id = product_id; this.order_date = order_date; this.unit = unit;
    }
}

class Solution {
    public List<List<String>> productsOrdered(List<Product> products, List<Order> orders) {
        HashMap<Integer, String> pname = new HashMap<>();
        for (Product p : products) pname.put(p.product_id, p.product_name);
        HashMap<Integer, Integer> units = new HashMap<>();
        for (Order o : orders) {
            if (o.order_date.compareTo("2020-02-01") >= 0 && o.order_date.compareTo("2020-03-01") < 0)
                units.merge(o.product_id, o.unit, Integer::sum);
        }
        List<List<String>> result = new ArrayList<>();
        for (Map.Entry<Integer, Integer> kv : units.entrySet()) {
            if (kv.getValue() >= 100 && pname.containsKey(kv.getKey()))
                result.add(Arrays.asList(pname.get(kv.getKey()), String.valueOf(kv.getValue())));
        }
        return result;
    }
}

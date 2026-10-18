import java.util.*;

class Product {
    int productId;
    Integer store1; // use Integer to allow null
    Integer store2;
    Integer store3;
    public Product(int productId, Integer store1, Integer store2, Integer store3) {
        this.productId = productId;
        this.store1 = store1;
        this.store2 = store2;
        this.store3 = store3;
    }
}

class Solution {
    public List<Object[]> rearrange(List<Product> products) {
        List<Object[]> res = new ArrayList<>();
        for (Product p : products) {
            if (p.store1 != null) {
                res.add(new Object[]{p.productId, "store1", p.store1});
            }
            if (p.store2 != null) {
                res.add(new Object[]{p.productId, "store2", p.store2});
            }
            if (p.store3 != null) {
                res.add(new Object[]{p.productId, "store3", p.store3});
            }
        }
        return res;
    }
}

import java.util.*;

class Product {
    public int product_id;
    public String low_fats;
    public String recyclable;
    public Product(int product_id, String low_fats, String recyclable) {
        this.product_id = product_id; this.low_fats = low_fats; this.recyclable = recyclable;
    }
}

class Solution {
    public List<List<String>> recyclableProducts(List<Product> products) {
        List<List<String>> result = new ArrayList<>();
        for (Product p : products)
            if ("Y".equals(p.low_fats) && "Y".equals(p.recyclable))
                result.add(Arrays.asList(String.valueOf(p.product_id)));
        return result;
    }
}

import java.util.*;

class Product { int productId; String productName; }
class Sale { int saleId; int productId; int year; int quantity; int price; }

class Solution {
    public List<List<String>> productSalesAnalysisI(List<Product> products, List<Sale> sales) {
        Map<Integer, String> pname = new HashMap<>();
        for (Product p : products) pname.put(p.productId, p.productName);
        List<List<String>> res = new ArrayList<>();
        for (Sale s : sales) {
            String pn = pname.get(s.productId);
            if (pn != null) {
                res.add(Arrays.asList(pn, String.valueOf(s.year), String.valueOf(s.price)));
            }
        }
        return res;
    }
}

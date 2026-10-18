import java.util.*;
class Product { int product_id; String product_name; }
class Sale { int product_id; String sale_date; }
class Solution {
    public List<List<String>> salesAnalysis(List<Product> products, List<Sale> sales) {
        Map<Integer,String[]> agg = new HashMap<>();
        Map<Integer,String> name = new HashMap<>();
        for (Product p : products) name.put(p.product_id, p.product_name);
        for (Sale s : sales) {
            if (!agg.containsKey(s.product_id)) agg.put(s.product_id, new String[]{s.sale_date,s.sale_date});
            else {
                String[] a = agg.get(s.product_id);
                a[0] = a[0].compareTo(s.sale_date)<0 ? a[0] : s.sale_date;
                a[1] = a[1].compareTo(s.sale_date)>0 ? a[1] : s.sale_date;
            }
        }
        List<List<String>> r = new ArrayList<>();
        for (Map.Entry<Integer,String[]> e : agg.entrySet()) {
            if (e.getValue()[0].compareTo("2019-01-01")>=0 && e.getValue()[1].compareTo("2019-03-31")<=0)
                r.add(Arrays.asList(String.valueOf(e.getKey()), name.get(e.getKey())));
        }
        return r;
    }
}

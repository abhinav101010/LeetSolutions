import java.util.*;

class Solution {
    static class Activities {
        String sell_date;
        String product;
        
        public Activities(String sell_date, String product) {
            this.sell_date = sell_date;
            this.product = product;
        }
    }
    
    static class Result {
        String sell_date;
        int num_sold;
        String products;
        
        public Result(String sell_date, int num_sold, String products) {
            this.sell_date = sell_date;
            this.num_sold = num_sold;
            this.products = products;
        }
    }
    
    public List<Result> groupSoldProducts(List<Activities> activities) {
        List<Result> results = new ArrayList<>();
        TreeMap<String, TreeSet<String>> dateToProducts = new TreeMap<>();
        for (Activities a : activities) {
            dateToProducts.computeIfAbsent(a.sell_date, k -> new TreeSet<>()).add(a.product);
        }
        for (Map.Entry<String, TreeSet<String>> entry : dateToProducts.entrySet()) {
            String date = entry.getKey();
            TreeSet<String> prodSet = entry.getValue();
            StringBuilder sb = new StringBuilder();
            for (String p : prodSet) {
                if (sb.length() > 0) sb.append(",");
                sb.append(p);
            }
            results.add(new Result(date, prodSet.size(), sb.toString()));
        }
        return results;
    }
}

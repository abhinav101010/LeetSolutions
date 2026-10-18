import java.util.*;

class Price {
    int product_id;
    String start_date;
    String end_date;
    int price;
    Price(int product_id, String start_date, String end_date, int price) {
        this.product_id = product_id; this.start_date = start_date; this.end_date = end_date; this.price = price;
    }
}

class Unit {
    int product_id;
    String purchase_date;
    int units;
    Unit(int product_id, String purchase_date, int units) {
        this.product_id = product_id; this.purchase_date = purchase_date; this.units = units;
    }
}

class Result {
    int product_id;
    double average_price;
    Result(int product_id, double average_price) {
        this.product_id = product_id; this.average_price = average_price;
    }
}

class Solution {
    public List<Result> averageSellingPrice(List<Price> prices, List<Unit> units) {
        Map<Integer, Double> avg = new HashMap<>();
        for (Price p : prices) avg.put(p.product_id, 0.0);
        Map<Integer, List<Unit>> byProd = new HashMap<>();
        for (Unit u : units) {
            byProd.computeIfAbsent(u.product_id, k -> new ArrayList<>()).add(u);
        }
        for (Map.Entry<Integer, List<Unit>> kv : byProd.entrySet()) {
            int pid = kv.getKey();
            if (!avg.containsKey(pid)) avg.put(pid, 0.0);
            double sumPu = 0.0;
            double sumU = 0.0;
            for (Unit u : kv.getValue()) {
                for (Price p : prices) {
                    if (p.product_id == pid && u.purchase_date.compareTo(p.start_date) >= 0 && u.purchase_date.compareTo(p.end_date) <= 0) {
                        sumPu += (double) p.price * (double) u.units;
                        sumU += (double) u.units;
                        break;
                    }
                }
            }
            if (sumU > 0.0) {
                avg.put(pid, Math.round(sumPu / sumU * 100.0) / 100.0);
            } else {
                avg.put(pid, 0.0);
            }
        }
        List<Result> ans = new ArrayList<>();
        for (Map.Entry<Integer, Double> kv : avg.entrySet()) {
            ans.add(new Result(kv.getKey(), kv.getValue()));
        }
        return ans;
    }
}

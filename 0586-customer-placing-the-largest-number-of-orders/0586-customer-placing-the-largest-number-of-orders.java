import java.util.*;

class Orders {
    public int order_number;
    public int customer_number;
    public Orders(int order_number, int customer_number) {
        this.order_number = order_number; this.customer_number = customer_number;
    }
}

class Solution {
    public List<List<String>> largestOrders(List<Orders> orders) {
        TreeMap<Integer, Integer> cnt = new TreeMap<>();
        for (Orders o : orders) cnt.merge(o.customer_number, 1, Integer::sum);
        int bestCust = -1, bestCnt = -1;
        for (Map.Entry<Integer, Integer> kv : cnt.entrySet()) {
            if (kv.getValue() > bestCnt) {
                bestCnt = kv.getValue();
                bestCust = kv.getKey();
            }
        }
        List<List<String>> result = new ArrayList<>();
        if (bestCust != -1) result.add(Arrays.asList(String.valueOf(bestCust)));
        return result;
    }
}

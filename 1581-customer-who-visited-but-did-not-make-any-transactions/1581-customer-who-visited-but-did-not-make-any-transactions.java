import java.util.*;

class Visit {
    int visit_id;
    int customer_id;
    Visit(int visit_id, int customer_id) { this.visit_id = visit_id; this.customer_id = customer_id; }
}

class Transaction {
    int transaction_id;
    int visit_id;
    int amount;
    Transaction(int transaction_id, int visit_id, int amount) {
        this.transaction_id = transaction_id; this.visit_id = visit_id; this.amount = amount;
    }
}

class Result {
    int customer_id;
    int count_no_trans;
    Result(int customer_id, int count_no_trans) {
        this.customer_id = customer_id; this.count_no_trans = count_no_trans;
    }
}

class Solution {
    public List<Result> customerVisitsWithoutTransactions(List<Visit> visits, List<Transaction> transactions) {
        Set<Integer> withTrans = new HashSet<>();
        for (Transaction t : transactions) withTrans.add(t.visit_id);
        Map<Integer, Integer> cnt = new HashMap<>();
        for (Visit v : visits) {
            if (!withTrans.contains(v.visit_id)) {
                cnt.put(v.customer_id, cnt.getOrDefault(v.customer_id, 0) + 1);
            }
        }
        List<Result> ans = new ArrayList<>();
        for (Map.Entry<Integer, Integer> kv : cnt.entrySet()) {
            ans.add(new Result(kv.getKey(), kv.getValue()));
        }
        return ans;
    }
}

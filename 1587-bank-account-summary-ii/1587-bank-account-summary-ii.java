import java.util.*;

class User { int account; String name; }
class Transaction { int transId; int account; int amount; String transactedOnDate; }

class Solution {
    public List<List<String>> bankAccountSummaryII(List<User> users, List<Transaction> transactions) {
        Map<Integer, String> nameByAccount = new HashMap<>();
        for (User u : users) nameByAccount.put(u.account, u.name);
        Map<Integer, Long> balance = new HashMap<>();
        for (Transaction t : transactions) balance.merge(t.account, (long) t.amount, Long::sum);
        List<List<String>> res = new ArrayList<>();
        for (User u : users) {
            Long bal = balance.get(u.account);
            if (bal != null && bal > 10000) {
                res.add(Arrays.asList(u.name, String.valueOf(bal)));
            }
        }
        return res;
    }
}

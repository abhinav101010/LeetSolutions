import java.util.*;

class Solution {
    private int n;
    private int[] price;
    private List<int[]> special;
    private Map<String, Integer> memo;
    
    public int shoppingOffers(List<Integer> priceList, List<List<Integer>> specialList, List<Integer> needsList) {
        n = priceList.size();
        price = new int[n];
        for (int i = 0; i < n; i++) price[i] = priceList.get(i);
        special = new ArrayList<>();
        for (List<Integer> s : specialList) special.add(s.stream().mapToInt(Integer::intValue).toArray());
        memo = new HashMap<>();
        return dfs(toArray(needsList));
    }
    
    private int[] toArray(List<Integer> list) {
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) arr[i] = list.get(i);
        return arr;
    }
    
    private String key(int[] arr) {
        StringBuilder sb = new StringBuilder();
        for (int v : arr) sb.append(v).append(",");
        return sb.toString();
    }
    
    private int dfs(int[] needs) {
        String k = key(needs);
        if (memo.containsKey(k)) return memo.get(k);
        
        int res = 0;
        for (int i = 0; i < n; i++) res += price[i] * needs[i];
        
        for (int[] offer : special) {
            boolean valid = true;
            for (int i = 0; i < n; i++) {
                if (needs[i] < offer[i]) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                int[] newNeeds = new int[n];
                for (int i = 0; i < n; i++) newNeeds[i] = needs[i] - offer[i];
                res = Math.min(res, offer[n] + dfs(newNeeds));
            }
        }
        
        memo.put(k, res);
        return res;
    }
}
import java.util.*;

class Query {
    String query_name;
    String result;
    int position;
    int rating;
    Query(String query_name, String result, int position, int rating) {
        this.query_name = query_name; this.result = result; this.position = position; this.rating = rating;
    }
}

class Solution {
    public List<List<String>> queriesQualityAndPercentage(List<Query> queries) {
        Map<String, List<Query>> byName = new HashMap<>();
        for (Query q : queries) byName.computeIfAbsent(q.query_name, k -> new ArrayList<>()).add(q);
        List<List<String>> ans = new ArrayList<>();
        for (Map.Entry<String, List<Query>> kv : byName.entrySet()) {
            String name = kv.getKey();
            List<Query> qs = kv.getValue();
            int n = qs.size();
            double quality = 0.0;
            double poor = 0.0;
            for (Query q : qs) {
                quality += (double) q.rating / (double) q.position;
                if (q.rating < 3) poor += 1.0;
            }
            quality /= n;
            poor = poor / n * 100.0;
            ans.add(Arrays.asList(name, String.format("%.2f", quality), String.format("%.2f", poor)));
        }
        return ans;
    }
}

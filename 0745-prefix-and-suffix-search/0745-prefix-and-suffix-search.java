import java.util.HashMap;
import java.util.Map;

class WordFilter {
    private Map<String, Integer> map;

    public WordFilter(String[] words) {
        map = new HashMap<>();
        for (int weight = 0; weight < words.length; weight++) {
            String word = words[weight];
            int n = word.length();
            for (int i = 0; i <= n; i++) {
                String pre = word.substring(0, i);
                for (int j = 0; j <= n; j++) {
                    String suf = word.substring(j);
                    String key = pre + "#" + suf;
                    map.put(key, weight); // later weight overrides
                }
            }
        }
    }

    public int f(String prefix, String suffix) {
        String key = prefix + "#" + suffix;
        Integer v = map.get(key);
        return v == null ? -1 : v;
    }
}

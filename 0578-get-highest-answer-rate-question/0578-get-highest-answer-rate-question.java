import java.util.*;

class SurveyLog {
    public int question_id;
    public String action;
    public SurveyLog(int question_id, String action) { this.question_id = question_id; this.action = action; }
}

class Solution {
    public List<List<String>> highestAnswerRate(List<SurveyLog> log) {
        HashMap<Integer, int[]> q = new HashMap<>();
        for (SurveyLog l : log) {
            int[] pr = q.computeIfAbsent(l.question_id, k -> new int[2]);
            if ("answer".equals(l.action)) pr[0]++;
            else if ("show".equals(l.action)) pr[1]++;
        }
        List<Map.Entry<Integer, Double>> rows = new ArrayList<>();
        for (Map.Entry<Integer, int[]> kv : q.entrySet()) {
            if (kv.getValue()[0] > 0) {
                double rate = kv.getValue()[1] == 0 ? 0.0 : (double) kv.getValue()[0] / kv.getValue()[1];
                rows.add(new AbstractMap.SimpleEntry<>(kv.getKey(), rate));
            }
        }
        rows.sort((a, b) -> {
            int cmp = Double.compare(b.getValue(), a.getValue());
            if (cmp != 0) return cmp;
            return Integer.compare(a.getKey(), b.getKey());
        });
        List<List<String>> result = new ArrayList<>();
        if (!rows.isEmpty()) result.add(Arrays.asList(String.valueOf(rows.get(0).getKey())));
        return result;
    }
}

import java.util.*;

class Score {
    int id;
    double score;
    
    public Score(int id, double score) {
        this.id = id;
        this.score = score;
    }
}

class Solution {
    public List<int[]> rankScores(List<Score> scores) {
        List<Score> list = new ArrayList<>(scores);
        list.sort((a, b) -> {
            if (a.score != b.score) {
                return Double.compare(b.score, a.score);
            }
            return Integer.compare(a.id, b.id);
        });
        List<int[]> res = new ArrayList<>();
        int rank = 0;
        double prev = -1000000000.0;
        for (Score sc : list) {
            if (Math.abs(sc.score - prev) > 1e-12) {
                rank++;
                prev = sc.score;
            }
            res.add(new int[]{(int)Math.round(sc.score * 100), rank});
        }
        return res;
    }
    
    // Simplified version returning list of (score, rank) as doubles/ints for general use
    public List<Object[]> rankScoresSimple(List<Score> scores) {
        List<Score> list = new ArrayList<>(scores);
        list.sort((a, b) -> {
            if (a.score > b.score + 1e-12) return -1;
            if (b.score > a.score + 1e-12) return 1;
            return Integer.compare(a.id, b.id);
        });
        List<Object[]> res = new ArrayList<>();
        int rank = 0;
        double prev = -Double.MAX_VALUE;
        for (Score sc : list) {
            if (Math.abs(sc.score - prev) > 1e-12) {
                rank++;
                prev = sc.score;
            }
            res.add(new Object[]{sc.score, rank});
        }
        return res;
    }
}

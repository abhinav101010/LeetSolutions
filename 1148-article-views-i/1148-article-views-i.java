import java.util.*;

class Solution {
    static class View {
        int article_id;
        int author_id;
        int viewer_id;
        String view_date;
        
        public View(int article_id, int author_id, int viewer_id, String view_date) {
            this.article_id = article_id;
            this.author_id = author_id;
            this.viewer_id = viewer_id;
            this.view_date = view_date;
        }
    }
    
    public List<Integer> articleViewsI(List<View> views) {
        Set<Integer> seen = new HashSet<>();
        for (View v : views) {
            if (v.author_id == v.viewer_id) {
                seen.add(v.author_id);
            }
        }
        List<Integer> result = new ArrayList<>(seen);
        Collections.sort(result);
        return result;
    }
}

import java.util.*;

class Solution {
    static class Cinema {
        int id;
        String movie;
        String description;
        double rating;
        
        public Cinema(int id, String movie, String description, double rating) {
            this.id = id;
            this.movie = movie;
            this.description = description;
            this.rating = rating;
        }
    }
    
    public List<Cinema> notBoringMovies(List<Cinema> cinema) {
        List<Cinema> result = new ArrayList<>(cinema);
        result.removeIf(c -> c.id % 2 == 0 || "boring".equals(c.description));
        result.sort((a, b) -> {
            if (a.rating != b.rating) {
                // descending order of rating
                return Double.compare(b.rating, a.rating);
            }
            return Integer.compare(a.id, b.id);
        });
        return result;
    }
}

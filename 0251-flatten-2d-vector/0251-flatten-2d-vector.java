import java.util.*;

class Vector2D {
    private List<List<Integer>> vec;
    private int i = 0, j = 0;
    
    public Vector2D(List<List<Integer>> vec) {
        this.vec = vec;
    }
    
    public int next() {
        advance();
        return vec.get(i).get(j++);
    }
    
    public boolean hasNext() {
        advance();
        return i < vec.size();
    }
    
    private void advance() {
        while (i < vec.size() && j >= vec.get(i).size()) {
            i++;
            j = 0;
        }
    }
}
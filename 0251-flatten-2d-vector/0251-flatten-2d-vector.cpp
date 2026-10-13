class Vector2D {
public:
    vector<vector<int>>& vec;
    int i = 0, j = 0;
    
    Vector2D(vector<vector<int>>& vec): vec(vec) {}
    
    void advance() {
        while (i < vec.size() && j >= vec[i].size()) {
            i++; j = 0;
        }
    }
    
    int next() {
        advance();
        return vec[i][j++];
    }
    
    bool hasNext() {
        advance();
        return i < vec.size();
    }
};
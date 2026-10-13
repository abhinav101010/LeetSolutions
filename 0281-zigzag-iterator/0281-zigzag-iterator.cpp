class ZigzagIterator {
public:
    vector<int> v1, v2;
    queue<tuple<int,int,int>> q; // index, listId, size
    ZigzagIterator(vector<int>& v1, vector<int>& v2): v1(v1), v2(v2) {
        if (!v1.empty()) q.push(make_tuple(0, 0, v1.size()));
        if (!v2.empty()) q.push(make_tuple(0, 1, v2.size()));
    }
    int next() {
        auto [idx, listId, size] = q.front(); q.pop();
        int val = listId == 0 ? v1[idx] : v2[idx];
        if (idx + 1 < size) {
            q.push(make_tuple(idx + 1, listId, size));
        }
        return val;
    }
    bool hasNext() {
        return !q.empty();
    }
};
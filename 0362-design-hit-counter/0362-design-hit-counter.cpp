class HitCounter {
public:
    queue<int> q;
    HitCounter() {
    }
    void hit(int timestamp) {
        q.push(timestamp);
    }
    int getHits(int timestamp) {
        while (!q.empty() && q.front() <= timestamp - 300) {
            q.pop();
        }
        return q.size();
    }
};
class MovingAverage {
public:
    queue<int> q;
    int size;
    long sum;
    MovingAverage(int size) {
        this->size = size;
        sum = 0;
    }
    double next(int val) {
        if ((int)q.size() == size) {
            sum -= q.front();
            q.pop();
        }
        q.push(val);
        sum += val;
        return (double)sum / q.size();
    }
};
class ZeroEvenOdd {
    int n; mutex m; condition_variable cv; int state=0;
public:
    ZeroEvenOdd(int n):n(n){}
    void zero(function<void(int)> printNumber){ for(int i=1;i<=n;i++){ unique_lock<mutex> lk(m); cv.wait(lk,[&]{return state==0;}); printNumber(0); state=(i%2)?1:2; cv.notify_all(); } }
    void even(function<void(int)> printNumber){ for(int i=2;i<=n;i+=2){ unique_lock<mutex> lk(m); cv.wait(lk,[&]{return state==2;}); printNumber(i); state=0; cv.notify_all(); } }
    void odd(function<void(int)> printNumber){ for(int i=1;i<=n;i+=2){ unique_lock<mutex> lk(m); cv.wait(lk,[&]{return state==1;}); printNumber(i); state=0; cv.notify_all(); } }
};
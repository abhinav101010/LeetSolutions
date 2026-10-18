class H2O {
    mutex m; condition_variable cv; int h=0;
public:
    H2O(){}
    void hydrogen(function<void()> releaseHydrogen){ unique_lock<mutex> lk(m); cv.wait(lk,[&]{return h<2;}); h++; releaseHydrogen(); if(h==2) cv.notify_all(); lk.unlock(); cv.wait(lk,[&]{return h==0;}); }
    void oxygen(function<void()> releaseOxygen){ unique_lock<mutex> lk(m); cv.wait(lk,[&]{return h==2;}); releaseOxygen(); h=0; cv.notify_all(); }
};
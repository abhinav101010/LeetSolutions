class ZeroEvenOdd {
    private int n; private Semaphore z=new Semaphore(1), e=new Semaphore(0), o=new Semaphore(0);
    public ZeroEvenOdd(int n){this.n=n;}
    public void zero(IntConsumer printNumber) throws InterruptedException {
        for(int i=1;i<=n;i++){ z.acquire(); printNumber.accept(0); (i%2==0?e:o).release(); }
    }
    public void even(IntConsumer printNumber) throws InterruptedException {
        for(int i=2;i<=n;i+=2){ e.acquire(); printNumber.accept(i); z.release(); }
    }
    public void odd(IntConsumer printNumber) throws InterruptedException {
        for(int i=1;i<=n;i+=2){ o.acquire(); printNumber.accept(i); z.release(); }
    }
}
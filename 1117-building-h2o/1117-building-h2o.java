class H2O {
    private Semaphore h=new Semaphore(2), o=new Semaphore(0);
    public H2O(){}
    public void hydrogen(Runnable r) throws InterruptedException { h.acquire(); r.run(); if(h.availablePermits()==0) o.release(); }
    public void oxygen(Runnable r) throws InterruptedException { o.acquire(); r.run(); h.release(2); }
}
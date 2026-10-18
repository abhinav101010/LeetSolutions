from threading import Semaphore
class ZeroEvenOdd:
    def __init__(self,n):
        self.n=n; self.z=Semaphore(1); self.e=Semaphore(0); self.o=Semaphore(0)
    def zero(self,printNumber):
        for i in range(1,self.n+1):
            self.z.acquire(); printNumber(0); (self.o if i%2 else self.e).release()
    def even(self,printNumber):
        for i in range(2,self.n+1,2):
            self.e.acquire(); printNumber(i); self.z.release()
    def odd(self,printNumber):
        for i in range(1,self.n+1,2):
            self.o.acquire(); printNumber(i); self.z.release()

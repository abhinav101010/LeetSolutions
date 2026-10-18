class Foo:
    def __init__(self):
        self.l2 = threading.Lock()
        self.l3 = threading.Lock()
        self.l2.acquire()
        self.l3.acquire()

    def first(self, printFirst):
        printFirst()
        self.l2.release()

    def second(self, printSecond):
        self.l2.acquire()
        printSecond()
        self.l3.release()

    def third(self, printThird):
        self.l3.acquire()
        printThird()

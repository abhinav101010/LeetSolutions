import threading
from typing import Callable

class FizzBuzz:
    def __init__(self, n: int):
        self.n = n
        self.lock = threading.Lock()
        self.num = 1

    def fizz(self, printFizz: Callable[[], None]) -> None:
        while self.num <= self.n:
            with self.lock:
                if self.num <= self.n and self.num % 3 == 0 and self.num % 5 != 0:
                    printFizz()
                    self.num += 1

    def buzz(self, printBuzz: Callable[[], None]) -> None:
        while self.num <= self.n:
            with self.lock:
                if self.num <= self.n and self.num % 5 == 0 and self.num % 3 != 0:
                    printBuzz()
                    self.num += 1

    def fizzbuzz(self, printFizzBuzz: Callable[[], None]) -> None:
        while self.num <= self.n:
            with self.lock:
                if self.num <= self.n and self.num % 3 == 0 and self.num % 5 == 0:
                    printFizzBuzz()
                    self.num += 1

    def number(self, printNumber: Callable[[int], None]) -> None:
        while self.num <= self.n:
            with self.lock:
                if self.num <= self.n and self.num % 3 != 0 and self.num % 5 != 0:
                    printNumber(self.num)
                    self.num += 1

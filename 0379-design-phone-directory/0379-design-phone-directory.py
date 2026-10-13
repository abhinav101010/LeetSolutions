class PhoneDirectory:
    def __init__(self, maxNumbers: int):
        self.available = set(range(maxNumbers))
        self.maxNumbers = maxNumbers
    
    def get(self) -> int:
        if not self.available:
            return -1
        num = self.available.pop()
        return num
    
    def check(self, number: int) -> bool:
        return number in self.available
    
    def release(self, number: int) -> None:
        if number < self.maxNumbers:
            self.available.add(number)
class TwoSum:
    def __init__(self):
        self.count = {}
    
    def add(self, number: int) -> None:
        self.count[number] = self.count.get(number, 0) + 1
    
    def find(self, value: int) -> bool:
        for num in self.count:
            complement = value - num
            if complement in self.count:
                if complement != num:
                    return True
                if self.count[num] > 1:
                    return True
        return False
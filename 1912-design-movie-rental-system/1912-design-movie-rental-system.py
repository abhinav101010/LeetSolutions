class MovieRentingSystem:

    def __init__(self, n, entries):
        self.available = defaultdict(lambda: SortedList())
        self.price_map = {}
        for shop, movie, price in entries:
            self.available[movie].add((price, shop))
            self.price_map[self.f(shop, movie)] = price
        self.rented = SortedList()

    def search(self, movie):
        return [shop for _, shop in self.available[movie][:5]]

    def rent(self, shop, movie):
        price = self.price_map[self.f(shop, movie)]
        self.available[movie].remove((price, shop))
        self.rented.add((price, shop, movie))

    def drop(self, shop, movie):
        price = self.price_map[self.f(shop, movie)]
        self.rented.remove((price, shop, movie))
        self.available[movie].add((price, shop))

    def report(self):
        return [[shop, movie] for _, shop, movie in self.rented[:5]]

    def f(self, shop, movie):
        return shop << 30 | movie


# Your MovieRentingSystem object will be instantiated and called as such:
# obj = MovieRentingSystem(n, entries)
# param_1 = obj.search(movie)
# obj.rent(shop,movie)
# obj.drop(shop,movie)
# param_4 = obj.report()

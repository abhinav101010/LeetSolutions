class UndergroundSystem:

    def __init__(self):
        self.check_ins = {}
        self.routes = {}

    def checkIn(self, id: int, stationName: str, t: int) -> None:
        self.check_ins[id] = (stationName, t)

    def checkOut(self, id: int, stationName: str, t: int) -> None:
        start_station, start_time = self.check_ins.pop(id)
        route = start_station + "->" + stationName
        duration = t - start_time
        if route in self.routes:
            total, count = self.routes[route]
            self.routes[route] = (total + duration, count + 1)
        else:
            self.routes[route] = (duration, 1)

    def getAverageTime(self, startStation: str, endStation: str) -> float:
        route = startStation + "->" + endStation
        total, count = self.routes[route]
        return total / count
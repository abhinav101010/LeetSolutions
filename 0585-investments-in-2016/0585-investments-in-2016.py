class Insurance:
    def __init__(self, pid, tiv2015, tiv2016, lat, lon):
        self.pid = pid
        self.tiv2015 = tiv2015
        self.tiv2016 = tiv2016
        self.lat = lat
        self.lon = lon

class Solution:
    def investments2016(self, insurance):
        tivCount = {}
        locCount = {}
        for ins in insurance:
            tivCount[ins.tiv2015] = tivCount.get(ins.tiv2015, 0) + 1
            key = str(ins.lat) + "|" + str(ins.lon)
            locCount[key] = locCount.get(key, 0) + 1
        total = 0
        for ins in insurance:
            if tivCount.get(ins.tiv2015, 0) > 1:
                key = str(ins.lat) + "|" + str(ins.lon)
                if locCount.get(key, 0) == 1:
                    total += ins.tiv2016
        return total

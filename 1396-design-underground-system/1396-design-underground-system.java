import java.util.HashMap;
import java.util.Map;

class UndergroundSystem {

    class CheckIn {
        String station;
        int time;

        CheckIn(String station, int time) {
            this.station = station;
            this.time = time;
        }
    }

    class Route {
        int totalTime;
        int count;

        Route(int totalTime, int count) {
            this.totalTime = totalTime;
            this.count = count;
        }
    }

    private Map<Integer, CheckIn> checkIns;
    private Map<String, Route> routes;

    public UndergroundSystem() {
        checkIns = new HashMap<>();
        routes = new HashMap<>();
    }

    public void checkIn(int id, String stationName, int time) {
        checkIns.put(id, new CheckIn(stationName, time));
    }

    public void checkOut(int id, String stationName, int time) {

        CheckIn entry = checkIns.remove(id);

        String routeName = entry.station + "->" + stationName;

        int duration = time - entry.time;

        if (routes.containsKey(routeName)) {
            Route route = routes.get(routeName);

            route.totalTime += duration;
            route.count++;
        } else {
            routes.put(routeName, new Route(duration, 1));
        }
    }

    public double getAverageTime(String startStation, String endStation) {

        String routeName = startStation + "->" + endStation;

        Route route = routes.get(routeName);

        return (double) route.totalTime / route.count;
    }
}
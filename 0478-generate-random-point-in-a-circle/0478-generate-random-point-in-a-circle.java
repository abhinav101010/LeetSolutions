import java.util.*;

class Solution {
    private double radius;
    private double xCenter;
    private double yCenter;
    private Random rand = new Random();

    public Solution(double radius, double x_center, double y_center) {
        this.radius = radius;
        this.xCenter = x_center;
        this.yCenter = y_center;
    }

    public double[] randPoint() {
        double r = radius * Math.sqrt(rand.nextDouble());
        double theta = 2 * Math.PI * rand.nextDouble();
        double x = xCenter + r * Math.cos(theta);
        double y = yCenter + r * Math.sin(theta);
        return new double[]{x, y};
    }
}
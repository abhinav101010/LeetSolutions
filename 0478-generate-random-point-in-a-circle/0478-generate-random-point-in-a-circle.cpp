class Solution {
private:
    double radius;
    double xCenter;
    double yCenter;

public:
    Solution(double radius, double x_center, double y_center) : radius(radius), xCenter(x_center), yCenter(y_center) {}

    vector<double> randPoint() {
        double r = radius * sqrt((double)rand() / RAND_MAX);
        double theta = 2 * M_PI * (double)rand() / RAND_MAX;
        double x = xCenter + r * cos(theta);
        double y = yCenter + r * sin(theta);
        return {x, y};
    }
};
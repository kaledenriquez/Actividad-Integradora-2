#pragma once
#include <string>
#include <vector>

class Point {
public:
    int x, y;
    Point(int x, int y) : x(x), y(y) {}
    static double distance(const Point& p1, const Point& p2); // Ahora es estático
    static Point parse_point(const std::string& input);
    Point closest_point(const std::vector<Point>& points, const Point& target);
};

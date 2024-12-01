#include "point_utils.h"
#include <cmath>
#include <limits>
#include <sstream>

point parse_point(const std::string& input) {
    int x, y;
    char ignore;
    std::stringstream ss(input);
    ss >> ignore >> x >> ignore >> y >> ignore; // Leer formato (x,y)
    return point(x, y);
}

double distance(const point& p1, const point& p2) {
    return std::sqrt(std::pow(p2.x - p1.x, 2) + std::pow(p2.y - p1.y, 2));
}

point closest_point(const std::vector<point>& points, const point& target) {
    double min_distance = std::numeric_limits<double>::max();
    point closest = points[0];

    for (const auto& p : points) {
        double current_distance = distance(p, target);
        if (current_distance < min_distance) {
            min_distance = current_distance;
            closest = p;
        }
    }

    return closest;
}

#include "point.h"
#include <cmath>
#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <limits.h>
#include <cstdint>
#include <queue>
#include <cstring>
#include <cmath>
#include <sstream>

// Función para calcular la distancia euclidiana entre dos puntos (método estático)
double Point::distance(const Point& p1, const Point& p2) {
    return std::sqrt(std::pow(p2.x - p1.x, 2) + std::pow(p2.y - p1.y, 2));
}

// Función global para encontrar el punto más cercano usando búsqueda lineal
Point Point::closest_point(const std::vector<Point>& points, const Point& target) {
    double minDistance = std::numeric_limits<double>::max();
    Point closest = points[0];

    for (const auto& point : points) {
        double currentDistance = Point::distance(point, target); // Llamada estática
        if (currentDistance < minDistance) {
            minDistance = currentDistance;
            closest = point;
        }
    }

    return closest;
}

// Función para parsear un punto del formato "(x,y)" a la estructura Point
Point Point::parse_point(const std::string& input) {
    int x, y;
    char ignore;
    std::stringstream ss(input);
    ss >> ignore >> x >> ignore >> y >> ignore; // Leer formato (x,y)
    return Point(x, y);
}

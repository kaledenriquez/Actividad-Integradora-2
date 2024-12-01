#ifndef POINT_UTILS_H
#define POINT_UTILS_H

#include "point.h"
#include <string>
#include <vector>

point parse_point(const std::string& input);
double distance(const point& p1, const point& p2);
point closest_point(const std::vector<point>& points, const point& target);

#endif // POINT_UTILS_H

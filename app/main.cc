#include <iostream>
#include <vector>
#include <string>
#include "../src/include/algorithms.h"
#include "../src/utils/point.h"

int main() {
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> kruskal_matrix(n, std::vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> kruskal_matrix[i][j];
        }
    }

    std::vector<std::vector<int>> capacity_matrix(n, std::vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> capacity_matrix[i][j];
        }
    }

    std::vector<Point> points;
    std::string input;
    for (int i = 0; i < n; ++i) {
        std::cin >> input;
        points.push_back(Point::parse_point(input));
    }

    std::cin >> input;
    Point target = Point::parse_point(input);

    kruskal(n, kruskal_matrix);
    traveling_salesman(n, kruskal_matrix);

    int graph[100][100];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            graph[i][j] = capacity_matrix[i][j];
        }
    }

    int max_flow = fordFulkerson(graph, 0, n - 1, n);
    std::cout << "3.\n" << max_flow << std::endl;

    Point closest = target.closest_point(points, target);
    std::cout << "4.\n(" << closest.x << "," << closest.y << ")\n";

    return 0;
}
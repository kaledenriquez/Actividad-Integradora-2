#include "src/graph/kruskal.h"
#include "flow/ford_fulkerson.h"
#include "utils/point_utils.h"
#include "tsp/traveling_salesman.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<int>> kruskalMatrix(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> kruskalMatrix[i][j];
        }
    }

    vector<vector<int>> capacityMatrix(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> capacityMatrix[i][j];
        }
    }

    vector<Point> points;
    string input;
    for (int i = 0; i < N; ++i) {
        cin >> input;
        points.push_back(parsePoint(input));
    }

    cin >> input;
    Point target = parsePoint(input);

    kruskal(N, kruskalMatrix);
    travelingSalesman(N, kruskalMatrix);

    int graph[100][100];
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            graph[i][j] = capacityMatrix[i][j];
        }
    }

    int maxFlow = fordFulkerson(graph, 0, N - 1, N);
    cout << "3.\n" << maxFlow << endl;

    Point closest = closestPoint(points, target);
    cout << "4.\n(" << closest.x << "," << closest.y << ")\n";

    return 0;
}
#include "kruskal.h"
#include <algorithm>
#include <iostream>

Edge::Edge(int u, int v, int weight) : u(u), v(v), weight(weight) {}

bool compare_edges(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

void kruskal(int n, const std::vector<std::vector<int>>& graph) {
    UnionFind uf(n);
    std::vector<Edge> edges;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (graph[i][j] != 0) {
                edges.emplace_back(i, j, graph[i][j]);
            }
        }
    }

    std::sort(edges.begin(), edges.end(), compare_edges);

    std::vector<Edge> mst;
    int total_weight = 0;

    for (const auto& edge : edges) {
        if (uf.unionSets(edge.u, edge.v)) {
            mst.push_back(edge);
            total_weight += edge.weight;
        }
        if (mst.size() == n - 1) break;
    }

    std::cout << std::endl << "1.\n";
    for (const auto& edge : mst) {
        char colonia_u = 'A' + edge.u;
        char colonia_v = 'A' + edge.v;
        std::cout << "(" << colonia_u << ", " << colonia_v << ")\n";
    }
}
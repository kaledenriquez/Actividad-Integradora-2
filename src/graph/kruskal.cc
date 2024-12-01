#include "kruskal.h"
#include "union_find.h"
#include <algorithm>
#include <iostream>

bool compare_edges(const edge& a, const edge& b) {
    return a.weight < b.weight;
}

void kruskal(int n, const std::vector<std::vector<int>>& graph) {
    union_find uf(n);
    std::vector<edge> edges;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (graph[i][j] != 0) {
                edges.emplace_back(i, j, graph[i][j]);
            }
        }
    }

    std::sort(edges.begin(), edges.end(), compare_edges);

    std::vector<edge> mst;
    int total_weight = 0;

    for (const auto& e : edges) {
        if (uf.union_sets(e.u, e.v)) {
            mst.push_back(e);
            total_weight += e.weight;
        }
        if (mst.size() == n - 1) break;
    }

    std::cout << "1.\n";
    for (const auto& e : mst) {
        char colonia_u = 'A' + e.u;
        char colonia_v = 'A' + e.v;
        std::cout << "(" << colonia_u << ", " << colonia_v << ")\n";
    }
}

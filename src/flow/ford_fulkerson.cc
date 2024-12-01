#include "ford_fulkerson.h"
#include "breadth_first_search.h"
#include <climits>
#include <cstring>

int ford_fulkerson(int graph[100][100], int s, int t, int n) {
    int r_graph[100][100];
    for (int u = 0; u < n; u++) {
        for (int v = 0; v < n; v++) {
            r_graph[u][v] = graph[u][v];
        }
    }

    int parent[100];
    int max_flow = 0;

    while (breadth_first_search(r_graph, s, t, parent, n)) {
        int path_flow = INT_MAX;
        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            path_flow = std::min(path_flow, r_graph[u][v]);
        }

        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            r_graph[u][v] -= path_flow;
            r_graph[v][u] += path_flow;
        }

        max_flow += path_flow;
    }

    return max_flow;
}

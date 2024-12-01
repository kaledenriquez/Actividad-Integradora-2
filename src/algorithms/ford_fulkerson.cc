#include "ford_fulkerson.h"
#include <queue>
#include <cstring>
#include <limits.h>

using namespace std;

bool bfs(int r_graph[100][100], int s, int t, int parent[], int n) {
    bool visited[100];
    memset(visited, 0, sizeof(visited));

    std::queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < n; v++) {
            if (!visited[v] && r_graph[u][v] > 0) {
                if (v == t) {
                    parent[v] = u;
                    return true;
                }
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }

    return false;
}

int fordFulkerson(int graph[100][100], int s, int t, int n) {
    int r_graph[100][100];
    for (int u = 0; u < n; u++) {
        for (int v = 0; v < n; v++) {
            r_graph[u][v] = graph[u][v];
        }
    }

    int parent[100];
    int max_flow = 0;

    while (bfs(r_graph, s, t, parent, n)) {
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
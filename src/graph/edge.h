#ifndef EDGE_H
#define EDGE_H

struct edge {
    int u, v, weight;
    edge(int u, int v, int weight) : u(u), v(v), weight(weight) {}
};

#endif // EDGE_H

#pragma once
#include <vector>

void kruskal(int n, const std::vector<std::vector<int>>& graph);
void traveling_salesman(int n, const std::vector<std::vector<int>>& cost);
int fordFulkerson(int graph[100][100], int s, int t, int n);
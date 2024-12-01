#include "traveling_salesman.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

void traveling_salesman(int n, const std::vector<std::vector<int>>& cost) {
    std::vector<int> nodes;

    for (int i = 1; i < n; i++) nodes.push_back(i);

    int min_cost = INT_MAX;
    std::vector<int> best_route;

    do {
        int curr_cost = 0;
        int curr_node = 0;
        std::vector<int> route = {0};

        for (int i = 0; i < nodes.size(); i++) {
            curr_cost += cost[curr_node][nodes[i]];
            curr_node = nodes[i];
            route.push_back(curr_node);
        }

        curr_cost += cost[curr_node][0];
        route.push_back(0);

        if (curr_cost < min_cost) {
            min_cost = curr_cost;
            best_route = route;
        }
    } while (std::next_permutation(nodes.begin(), nodes.end()));

    std::cout << "2.\n";
    for (int i = 0; i < best_route.size(); i++) {
        std::cout << char('A' + best_route[i]) << " ";
    }
    std::cout << std::endl;
}

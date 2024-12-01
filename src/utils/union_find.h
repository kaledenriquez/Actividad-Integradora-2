#pragma once
#include <vector>

class UnionFind {
    std::vector<int> parent, rank;

public:
    UnionFind(int n);                 
    int find(int x);                  
    bool unionSets(int x, int y);     
};
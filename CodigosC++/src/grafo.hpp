#ifndef GRAFO_HPP
#define GRAFO_HPP

#include <vector>
#include <utility>
#include <limits>
#include <queue>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cmath>
#include <cstring>


using namespace std;
const int MAX_VERTICES = 25;

class Grafo {
private:
    vector<pair<int, int>> grafo[MAX_VERTICES];

public:
    void adicionarAresta(int u, int v, int peso);
    void imprimirGrafoNovo(int x);
    vector<int> dijkstra(int src);
    double closeness_centrality(int vertex);
};

#endif

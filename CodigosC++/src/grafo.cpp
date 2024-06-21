#include "grafo.hpp"

void Grafo::adicionarAresta(int u, int v, int peso) {
    grafo[u].push_back({v, peso});
    grafo[v].push_back({u, peso});
}

void Grafo::imprimirGrafoNovo(int x)
{
    std::cout<< "\nImprimindo o grafo normalizado " << x << "\n";
    for (int u = 0; u < MAX_VERTICES; u++) {
        if (!grafo[u].empty()) {
            for (const auto& vizinho : grafo[u]) {
                std::cout << "(" << vizinho.first << ", " << vizinho.second << ") ";
            }
            std::cout << "- " << closeness_centrality(u) << " " ;
            std::cout << "\n";
        }
    }
}

vector<int> Grafo::dijkstra(int src) {
    vector<int> dist(MAX_VERTICES, numeric_limits<int>::max());
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});
    dist[src] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        int d_u = pq.top().first;
        pq.pop();

        if (d_u > dist[u]) continue;

        for (const auto& edge : grafo[u]) {
            int v = edge.first;
            int weight = edge.second;
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

double Grafo::closeness_centrality(int vertex) {
    vector<int> shortest_paths = dijkstra(vertex);
    int total_distance = 0;

    for (int dist : shortest_paths) {
        total_distance += dist;
    }

    double closeness = (MAX_VERTICES - 1) / static_cast<double>(total_distance);
    return closeness;
}

#include "grafo.hpp"
#include "grafo.cpp"

// Matriz de adjacência para armazenar as arestas existentes
bool arestasAdicionadas[MAX_VERTICES][MAX_VERTICES] = {false};

int main() {

// Fixa a seed com um valor constante
srand(12345);

// Inicializa o gerador de números aleatórios
    srand((unsigned int)time(NULL));

    Grafo grafo[10];

    for (int x = 0; x < 10; x++)
    {
        for (int i = 0; i < MAX_VERTICES; i++) {
        int qntd_arestas = (rand() % 5) + 1;
        for (int j = 0; j < qntd_arestas; j++) {
            int destino = rand() % MAX_VERTICES;
            int peso = (rand() % 5) + 1;

            // Verifica se a aresta já foi adicionada
            if (!arestasAdicionadas[i][destino] && !arestasAdicionadas[destino][i] && i != destino) {
                grafo[x].adicionarAresta(i, destino, peso);
                // Marca a aresta como adicionada na matriz de adjacência
                arestasAdicionadas[i][destino] = true;
                arestasAdicionadas[destino][i] = true; // Grafo não orientado
                }
            }
        }

        int qntd_arestas = 0;
        int peso = 0;
        int destino = 0;
        memset(arestasAdicionadas, false, sizeof(arestasAdicionadas));
    // Testando o algoritmo de Dijkstra
    vector<int> distancias = grafo[x].dijkstra(0);

    cout << "\nDistancias minimas a partir do vertice 0:\n";
    for (int i = 0; i < MAX_VERTICES; i++) {
        if (distancias[i] != numeric_limits<int>::max()) {
            cout << "Vertice " << i << ": " << distancias[i] << "\n";
        } else {
            cout << "Vertice " << i << ": Infinito\n";
        }
    }

    // Calculando e imprimindo a centralidade de closeness para cada vértice
    cout << '\n';
    for (int v = 0; v < MAX_VERTICES; ++v) {
        double closeness = grafo[x].closeness_centrality(v);
        cout << "Medida de centralidade de proximidade do vertice " << v << ": " << closeness << endl;
    }
    grafo[x].imprimirGrafoNovo(x);
    }
    return 0;
}

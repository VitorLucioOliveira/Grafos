#include <iostream>
#include <vector>
#include <queue>
#include <algorithm> // for std::reverse
#define INT_MIN -1000000000
#define INT_MAX 1000000000
using namespace std;

int min(int a, int b)
{
    return a < b ? a : b;
}

int main()
{

    int N, M, destino; // vertices, arestas

    cin >> N >> M >> destino; // leitura de vertices e arestas

    vector<vector<pair<int, int>>> Grafo(N); // grafo

    for (int i = 0; i < M; i++)
    {
        int v, u, w; // u e v são os vertices e w é o peso da aresta v-->u
        cin >> v >> u >> w;
        Grafo[v].push_back({u, w}); // direcionando  v-->u e armazenando o peso w
    }

    vector<int> antecessores(N, -1); // vetor de antecessores
    vector<int> caminho;             // vetor de caminho

    std::priority_queue<pair<int, int>, std::vector<pair<int, int>>, std::greater<pair<int, int>>> fila_prioridade; // fila de prioridade (vertice, distancia)

    vector<int> dist(N, INT_MIN); // vetor de distancias
    dist[0] = INT_MAX;            // distancia do vertice 0 para ele mesmo é 0
    fila_prioridade.push({0, 0}); // inserindo o vertice 0 na fila de prioridade

    while (!fila_prioridade.empty())
    {
        int v = fila_prioridade.top().second; // vertice
        fila_prioridade.pop();                // removendo o vertice da fila de prioridade

        for (auto vertice : Grafo[v])
        {                              // para cada vertice adjacente a v
            int u = vertice.first;     // vertice adjacente
            int peso = vertice.second; // peso da aresta v-->u

            if (dist[u] < min(peso, dist[v]))
            {
                dist[u] = min(peso, dist[v]);
                fila_prioridade.push({dist[u], u});

                antecessores[u] = v; // atualize o antecessor do vertice adjacente
            }
        }
    }

    while (destino != -1)
    {                                    // enquanto o destino não for -1
        caminho.push_back(destino);      // insira o destino no vetor de caminho
        destino = antecessores[destino]; // atualize o destino para o antecessor do destino
    }

    reverse(caminho.begin(), caminho.end()); // inverta o vetor de caminho

    cout << "Caminho: ";
    for (int d : caminho)
    {
        cout << d << " ";
    }
    cout << endl;

    cout << "Distancias: ";
    for (int d : dist)
    {
        cout << (d == INT_MAX ? "∞" : to_string(d)) << " ";
    }
    cout << endl;
}
#include <iostream>
#include <vector>
#include <algorithm> // for std::reverse
#include <queue>
#define INT_MIN -1000000000
#define INT_MAX 1000000000
using namespace std;

int max(int a, int b)
{
    return a > b ? a : b;
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

    priority_queue<pair<int, int>> fila_prioridade; // fila de prioridade (vertice, distancia)

    vector<int> dist(N, INT_MAX); // vetor de distancias
    dist[0] = INT_MIN;            // distancia do vertice é -infinito
    fila_prioridade.push({0, 0}); // inserindo o vertice 0 na fila de prioridade

    while (!fila_prioridade.empty())
    {
        int v = fila_prioridade.top().second; // vertice
        fila_prioridade.pop();                // removendo o vertice da fila de prioridade

        for (auto vertice : Grafo[v])// para cada vertice adjacente a v
        {                              
            int u = vertice.first;     // vertice adjacente
            int peso = vertice.second; // peso da aresta v-->u

            if (dist[u] > max(peso, dist[v]))//se a distancia do vertice adjacente for maior que a distancia do maior entre o peso da aresta e a distancia do vertice atual
            {
                dist[u] = max(peso, dist[v]);// atualize a distancia do vertice adjacente
                fila_prioridade.push({dist[u], u});// insire o vertice adjacente na fila de prioridade

                antecessores[u] = v; // atualize o antecessor do vertice adjacente
            }
        }
    }

    while (destino != -1)// enquanto o destino não for -1
    {                                    
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
        cout << (d == INT_MIN ? "∞" : to_string(d)) << " ";
    }
    cout << endl;
}
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm> // for std::reverse
#define INT_MAX 1000000000
using namespace std;

int main(){
   
    int N, M , destino; //vertices, arestas

    cin >> N >> M >> destino; //leitura de vertices e arestas 

    vector<vector<pair<int,int>>> G(N); //grafo

    for(int i = 0; i < M; i++){
        int v, u, w; //u e v são os vertices e w é o peso da aresta v-->u
        cin >> v >> u >> w;
        G[v].push_back({u,w});//direcionando  v-->u e armazenando o peso w
    }

    vector<int> antecessores(N, -1); //vetor de antecessores
    vector<int> caminho; //vetor de caminho

    priority_queue<pair<int,int>> fila_prioridade; //fila de prioridade (vertice, distancia)

    vector<int> dist(N, INT_MAX); //vetor de distancias
    dist[0] = 0; //distancia do vertice 0 para ele mesmo é 0
    fila_prioridade.push({0,0}); //inserindo o vertice 0 na fila de prioridade

    while(!fila_prioridade.empty()){
        int v = fila_prioridade.top().second; //vertice
        fila_prioridade.pop(); //removendo o vertice da fila de prioridade

        if(v == destino) break; //se o vertice atual for o ultimo, pare

        for(auto edge : G[v]){ //para cada vertice adjacente a v
            int u = edge.first; //vertice adjacente
            int cost = edge.second; //peso da aresta v-->u
            
            if( dist[u] > dist[v] + cost){ //se a distancia do vertice adjacente for maior que a distancia do vertice atual + o peso da aresta
                dist[u] = dist[v] + cost; //atualize a distancia do vertice adjacente
                
                fila_prioridade.push({-dist[u], u}); //insire o vertice adjacente na fila de prioridade  com distâncias negativas para se aproveitar da prioridade da fila de prioridade de menor para maior

                antecessores[u] = v; //atualize o antecessor do vertice adjacente
            }
           
        }
    }

    while (destino != -1){ //enquanto o destino não for -1
        caminho.push_back(destino); //insira o destino no vetor de caminho
        destino = antecessores[destino]; //atualize o destino para o antecessor do destino
    }

    reverse(caminho.begin(), caminho.end()); //inverta o vetor de caminho para ser do inicio ao fim
    
    cout << "Caminho: ";
    for( int d: caminho){
        cout << d << " ";
    }
    cout << endl;

    cout << "Distancias: ";
    for( int d: dist){
        cout << (d == INT_MAX ? "∞" : to_string(d)) << " ";
    }
    cout << endl;
}
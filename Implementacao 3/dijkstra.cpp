#include <iostream>
#include <vector>
#include <queue>
#define INT_MAX 1000000000
using namespace std;

int main(){
   
    int N, M; //vertices, arestas

    cin >> N >> M; //leitura de vertices e arestas 

    vector<vector<pair<int,int>>> G(N); //grafo

    for(int i = 0; i < M; i++){
        int v, u, w; //u e v são os vertices e w é o peso da aresta v-->u
        cin >> v >> u >> w;
        v--; u--; //ajustando para o 0-based
        G[v].push_back({u,w});//direcionando  v-->u e armazenando o peso w
    }



    priority_queue<pair<int,int>> dijkstra; //fila de prioridade (vertice, distancia)

    vector<int> dist(N, INT_MAX); //vetor de distancias
    dist[0] = 0; //distancia do vertice 0 para ele mesmo é 0
    dijkstra.push({0,0}); //inserindo o vertice 0 na fila de prioridade

    while(!dijkstra.empty()){
        int v = dijkstra.top().second; //vertice
        int d = -dijkstra.top().first; //distancia em negativo prra começar do menor
        dijkstra.pop(); //removendo o vertice da fila de prioridade

        if(d != dist[v]) continue;//se a distancia armazenada for diferente da distancia atual, ignore

        for(auto edge : G[v]){ //para cada vertice adjacente a v
            int u = edge.first; //vertice adjacente
            int cost = edge.second; //peso da aresta v-->u
            
            if( dist[u] > dist[v] + cost){ //se a distancia do vertice adjacente for maior que a distancia do vertice atual + o peso da aresta
                dist[u] = dist[v] + cost; //atualize a distancia do vertice adjacente
                dijkstra.push({-dist[u], u}); //insira o vertice adjacente na fila de prioridade
            }
           
        }
    }

    for( int d: dist){
        cout << (d == INT_MAX ? -1 : d) << " ";
    }
    cout << endl;
}
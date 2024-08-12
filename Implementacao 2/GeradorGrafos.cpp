#include <iostream>
#include <cmath>

//------ Calculos -------//
int fatorial(int x)
{
    if (x <= 1)
    {
        return 1;
    }
    else
    {
        return x * fatorial(x - 1);
    }
}

int totalArestas(int k)
{
    int arestas = (k * (k - 1)) / 2;
    return pow(2, arestas);
}

int combinacao(int n, int p)
{
    int fatParen = fatorial((n - p)); //(n-p)!

    int divisor = fatorial(p) * fatParen; // p!(n-p)!

    return fatorial(n) / divisor; //  n!/p!(n-p)!
}

int totalSubgrafos(int n)
{

    int numSubgrafos = 0;

    for (int i = 1; i <= n; i++) // começa com 1 pois n]ao conta com o grafo vazio
    {
        int comb = combinacao(n, i);
        int arestas = totalArestas(i);

        numSubgrafos += comb * arestas;
    }

    return numSubgrafos;
}

int main()
{

    std::cout << "Gerador de subgrafos de um Grafo Completo" << std::endl;
    std::cout << "Digite o número de vértices do grafo: ";

    int n; // numero de vertices
    std::cin >> n;

    // int numSubgrarfos = totalSubgrafos(n);

    std::cout << totalSubgrafos(n) << std::endl;

    return 0;
}
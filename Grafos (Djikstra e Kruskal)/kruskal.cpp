#include <vector>
#include <iostream>
#include <string>
#include <initializer_list>
#include <algorithm>

#define verticeU first.first
#define verticeV first.second
#define peso second

typedef std::pair<int, int> aresta;
typedef std::initializer_list<std::initializer_list<int>> Matriz;

class Grafo
{
private:
    int custoMST;
    bool completo = false;
    std::vector<int> pai;
    std::vector<std::pair<aresta, int>> G;
    std::vector<std::pair<aresta, int>> mst;

    int procura(int i)
    {
        if (i == pai[i])
            return i;
        else
            return procura(pai[i]);
    }

    void uniao(int u, int v) { pai[u] = pai[v]; }

public:
    Grafo();
    Grafo(Matriz);
    void add_aresta(int, int, int);
    void MST();
    void print();
    ~Grafo();
};

Grafo::Grafo()
{
}

Grafo::Grafo(Matriz matriz)
{
    auto it = matriz.begin();
    auto it2 = it->begin();
    for (int i = 0; i < matriz.size(); i++)
    {
        for (int j = 0; j < matriz.size(); j++)
        {
            int p = *it2;
            if (p != 0)
                add_aresta(i, j, p);
            it2++;
        }
        it++;
        it2 = it->begin();
    }
}

void Grafo::add_aresta(int u, int v, int w)
{
    G.push_back(std::make_pair(aresta(u, v), w));
    completo = false;
}

void Grafo::MST()
{
    if (completo)
        return;

    pai.clear();
    mst.clear();
    for (int i = 0; i < G.size(); i++)
        pai.push_back(i);

    int u, v;
    custoMST = 0;

    std::sort(G.begin(), G.end(), [](auto &aresta1, auto &aresta2)
              { return aresta1.peso < aresta2.peso; });

    for (int aresta = 0; aresta < G.size(); aresta++)
    {
        u = procura(G[aresta].verticeU);
        v = procura(G[aresta].verticeV);

        if (u != v)
        {
            mst.push_back(G[aresta]);
            custoMST += G[aresta].peso;
            uniao(u, v);
        }
    }
    completo = true;
}

void Grafo::print()
{
    for (auto v : mst)
        std::cout << "{" << v.verticeU << ", " << v.verticeV << "} peso: " << v.peso << "\n";

    std::cout << "peso MST: " << custoMST << "\n";
}

Grafo::~Grafo()
{
}

int main()
{

    Grafo g = {{7, 20, 15, 9, 8, 10},
               {5, 40, 20, 10, 8, 15},
               {60, 6, 27, 80, 2, 90},
               {12, 42, 56, 48, 7, 5}};
    g.MST();
    g.print();

    Grafo f = {{2, 50, 13, 40, 8, 12},
               {33, 30, 40, 20, 5, 10},
               {22, 31, 34, 42, 50, 69},
               {0, 9, 3, 15, 45, 25}};

    f.MST();
    f.print();
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <initializer_list>
#include <exception>
#include <limits>
#define INFINITO std::numeric_limits<int>::max()

class Grafo
{
private:
    int qtd_vertices;

    std::vector<std::vector<int>> arestas;

    int menor_distancia(std::vector<int> &distancia, std::vector<bool> &marca)
    {
        int min = INFINITO, index;

        for (int i = 0; i < qtd_vertices; i++)
            if (marca[i] == false && min > distancia[i])
            {
                min = distancia[i];
                index = i;
            }
        return index;
    }

    int procura(int i, std::vector<int> &pai)
    {
        while (pai[i] != i)
            i = pai[i];

        return i;
    }

    void junta(int i, int j, std::vector<int> &pai)
    {
        int a = procura(i, pai);
        int b = procura(j, pai);
        pai[a] = b;
    }

public:
    Grafo(std::initializer_list<std::initializer_list<int>> matriz)
        : qtd_vertices(matriz.size())
    {
        for (auto it = matriz.begin(); it != matriz.end(); ++it)
            arestas.emplace_back(std::vector<int>(it->begin(), it->end()));
    }

    void arestas_de(int vertice)
    {
        try
        {
            for (int i = 0; i < qtd_vertices; i++)
                if (arestas.at(vertice).at(i) != 0)
                    std::cout << vertice << " -> " << i << ". Peso = " << arestas[vertice][i] << std::endl;
            printf("\n");
        }
        catch (const std::out_of_range &e)
        {
            std::cerr << "Out of range: " << e.what() << '\n';
        }
    }

    void peso(int de_vertice, int ate_vertice)
    {
        try
        {
            if (arestas.at(de_vertice).at(ate_vertice) != 0)
                std::cout << de_vertice << " -> " << ate_vertice << ". Peso = " << arestas[de_vertice][ate_vertice] << std::endl;
            else
                std::cout << "Aresta " << de_vertice << " -> " << ate_vertice << " nao existe" << std::endl;
            printf("\n");
        }
        catch (const std::out_of_range &e)
        {
            std::cerr << "Out of range: " << e.what() << '\n';
        }
    }

    void Dijkstra(int fonte, int destino = -1)
    {
        try
        {
            if (destino != -1)
                arestas.at(fonte).at(destino);
            else
                arestas.at(fonte);
        }
        catch (const std::out_of_range &e)
        {
            std::cerr << "Out of range: " << e.what() << '\n';
            return;
        }

        std::vector<bool> marca;
        std::vector<int> distancia;
        std::vector<int> predecessor;

        distancia.resize(qtd_vertices, INFINITO);
        marca.resize(qtd_vertices, false);

        distancia[fonte] = 0;

        for (int i = 0; i < qtd_vertices; i++)
        {
            int vertice_mais_proximo = menor_distancia(distancia, marca);
            marca[vertice_mais_proximo] = true;

            for (int vertice_atual = 0; vertice_atual < qtd_vertices; vertice_atual++)
            {
                if (arestas[vertice_mais_proximo][vertice_atual] > 0 && (marca[vertice_atual] == false && arestas[vertice_mais_proximo][vertice_atual] != INFINITO))
                {
                    int n = arestas[vertice_mais_proximo][vertice_atual] + distancia[vertice_mais_proximo];
                    if (n < distancia[vertice_atual])
                        distancia[vertice_atual] = n;
                }
            }
        }
        int j = 0;

        if (destino == -1)
            for (auto d : distancia)
                std::cout << fonte << " -> " << j++ << ". Distancia = " << d << std::endl;
        else
            std::cout << fonte << " -> " << destino << ". Distancia = " << distancia[destino] << std::endl;
        printf("\n");
    }

    ~Grafo()
    {
    }
};

int main()
{
    Grafo g = {{7, 20, 15, 9, 8, 10},
               {5, 40, 20, 10, 8, 15},
               {60, 6, 27, 80, 2, 90},
               {12, 42, 56, 48, 7, 5}};

    g.Dijkstra(1, 3);

    exit(0);
}
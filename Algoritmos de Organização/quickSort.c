#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int particiona(int *V, int inicio, int final)
{
    int esquerda, direita, pivot, aux;
    esquerda = inicio;
    direita = final;
    pivot = V[inicio];
    while (esquerda < direita)
    {
        while (V[esquerda] <= pivot)
        {
            esquerda++;
        }
        while (V[direita] > pivot)
        {
            direita--;
        }
        if (esquerda < direita)
        {
            aux = V[esquerda];
            V[esquerda] = V[direita];
            V[direita] = aux;
        }
    }
    V[inicio] = V[direita];
    V[direita] = pivot;
    return direita;
}

void quickSort(int *V, int inicio, int fim)
{
    int pivot;
    if (fim > inicio)
    {
        pivot = particiona(V, inicio, fim);
        quickSort(V, inicio, pivot - 1);
        quickSort(V, pivot + 1, fim);
    }
}

int main()
{
    int i = 0, tamanho;

    srand(time(NULL));

    printf("insira o tamanho do vetor:\n");
    scanf("%d", &tamanho);

    int vetor[tamanho];

    for (i = 0; i < tamanho; i++)
    {
        vetor[i] = rand() % 100 + 1;
    }

    printf("antes do quickSort:\n");

    for (i = 0; i < tamanho; i++)
    {
        printf("%d ", vetor[i]);
    }

    quickSort(vetor, 0, tamanho);

    printf("\ndepois do quickSort:\n");

    for (i = 0; i < tamanho; i++)
    {
        printf("%d ", vetor[i]);
    }

    exit(0);
}
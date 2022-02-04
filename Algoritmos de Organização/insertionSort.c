#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int V[], int N)
{
    int i, j, aux;
    for (i = 1; i < N; i++)
    {
        aux = V[i];
        for (j = i; (j > 0) && (aux < V[j - 1]); j--)
        {
            V[j] = V[j - 1];
        }
        V[j] = aux;
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

    printf("antes do insertionSort:\n");

    for (i = 0; i < tamanho; i++)
    {
        printf("%d ", vetor[i]);
    }

    insertionSort(vetor, tamanho);

    printf("\ndepois do insertionSort:\n");

    for (i = 0; i < tamanho; i++)
    {
        printf("%d ", vetor[i]);
    }

    exit(0);
}
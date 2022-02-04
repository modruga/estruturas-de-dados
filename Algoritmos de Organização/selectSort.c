#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int vetor[], int n)
{
    int i, j;

    for (i = 0; i < n - 1; i++)
    {
        int iMin = i;

        for (j = i + 1; j < n; j++)
        {
            if (vetor[j] < vetor[iMin])
            {
                iMin = j;
            }
        }

        int temp = vetor[i];
        vetor[i] = vetor[iMin];
        vetor[iMin] = temp;
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

    printf("antes do selectionSort:\n");

    for (i = 0; i < tamanho; i++)
    {
        printf("%d ", vetor[i]);
    }

    selectionSort(vetor, tamanho);

    printf("\ndepois do selectionSort:\n");

    for (i = 0; i < tamanho; i++)
    {
        printf("%d ", vetor[i]);
    }

    exit(0);
}
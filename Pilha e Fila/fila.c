#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct Pessoa
{
    char nome[30];
    int idade;
    struct Pessoa *prox;

} pessoa;

int isEmpty(pessoa **personPointer)
{
    if ((*personPointer) == NULL)
    {
        return 1;
    }
    else
        return 0;
}

void addPessoa(pessoa **vetor, pessoa **inivetor, pessoa **fimvetor)
{

    system("clear||cls");

    if (isEmpty(vetor) == 1)
    {

        (*vetor) = (pessoa *)malloc(sizeof(pessoa));
        printf("insira o nome da pessoa:\n");
        scanf("%s", (*vetor)->nome);
        system("clear||cls");
        printf("insira a idade da pessoa:\n");
        scanf("%d", &(*vetor)->idade);
        getchar();
        system("clear||cls");
        (*inivetor) = (*vetor);
        (*fimvetor) = (*vetor);
        (*vetor)->prox = NULL;

        return;
    }
    else
    {

        while ((*vetor)->prox != NULL)
        {

            (*vetor) = (*vetor)->prox;
        }

        (*vetor)->prox = (pessoa *)malloc(sizeof(pessoa));
        printf("insira o nome da pessoa:\n");
        scanf("%s", (*vetor)->prox->nome);
        printf("insira a idade da pessoa:\n");
        scanf("%d", &(*vetor)->prox->idade);
        (*vetor)->prox->prox = NULL;
        (*fimvetor) = (*vetor)->prox;

        return;
    }
}

void removePessoa(pessoa **vetor, pessoa **inivetor, pessoa **fimvetor)
{

    if ((*vetor) == NULL)
    {
        return;
    }

    else if ((*vetor) != NULL && (*vetor)->prox == NULL)
    {
        pessoa *deleta;
        deleta = (*vetor);
        (*vetor) = NULL;
        (*inivetor) = NULL;
        (*fimvetor) = NULL;
        free(deleta);
        return;
    }

    else if ((*vetor) != NULL && (*vetor)->prox != NULL)
    {
        pessoa *deleta;
        deleta = (*vetor);
        (*vetor) = (*vetor)->prox;
        (*inivetor) = (*vetor);
        free(deleta);
        return;
    }
}

int main()
{

    pessoa *vetor = NULL, *inivetor = NULL, *fimvetor = NULL;

    int r;

    for (;;)
    {

        printf("0. insere pessoa\n1. deleta pessoa\n2. imprime fila\n3. limpa fila\n4. sair\n\n");
        scanf("%d", &r);

        switch (r)
        {
        case 0:

            vetor = inivetor;
            addPessoa(&vetor, &inivetor, &fimvetor);
            system("clear||cls");
            break;

        case 1:

            vetor = inivetor;
            removePessoa(&vetor, &inivetor, &fimvetor);
            system("clear||cls");
            break;

        case 2:

            system("clear||cls");

            vetor = inivetor;

            while (vetor != NULL)
            {
                printf("%s, ", vetor->nome);
                printf("%d anos de idade.\n", vetor->idade);
                vetor = vetor->prox;
            }

            printf("\n");

            break;

        case 3:

            vetor = inivetor;

            while (vetor != NULL)
            {
                removePessoa(&vetor, &inivetor, &fimvetor);
            }

            break;

        case 4:

            free(vetor);
            exit(0);

            break;

        default:
            break;
        }
    }
}
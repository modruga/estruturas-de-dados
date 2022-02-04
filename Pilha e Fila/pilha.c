#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct Pessoa
{
    char nome[30];
    int idade;

    struct Pessoa *prox;

} pessoa;

int isEmpty(pessoa **vetor) //função de verificação que serve pra retornar 1 se o vetor estiver vazio, ou 0 se tiver conteúdo
{

    if ((*vetor) == NULL)
    {
        return 1;
    }
    else
        return 0;
}

void addPessoa(pessoa **vetor, pessoa **inivetor, pessoa **fimvetor) //função responsável pela adição de conteúdo no vetor principal
{
    if (isEmpty(vetor) == 1)
    {
        (*vetor) = (pessoa *)malloc(sizeof(pessoa));
        printf("insira o nome da pessoa:\n");
        scanf("%s", (*vetor)->nome);
        system("clear||cls");
        printf("insira a idade da pessoa:\n");
        scanf("%d", &(*vetor)->idade);
        (*vetor)->prox = NULL;
        (*inivetor) = (*vetor);
        (*fimvetor) = (*vetor);
        system("clear||cls");
    }
    else
    {
        pessoa *novoInicio = (pessoa *)malloc(sizeof(pessoa));
        printf("insira o nome da pessoa:\n");
        scanf("%s", novoInicio->nome);
        system("clear||cls");
        printf("insira a idade da pessoa:\n");
        scanf("%d", &novoInicio->idade);
        novoInicio->prox = (*vetor);
        (*vetor) = novoInicio;
        (*inivetor) = (*vetor);
        novoInicio = NULL;
        free(novoInicio);
    }
}

void deletaPessoa(pessoa **vetor, pessoa **inivetor, pessoa **fimvetor)
{
    if (isEmpty(vetor) == 1)
    {
        return;
    }
    else
    {
        pessoa *deleta = (*vetor);
        (*vetor) = (*vetor)->prox;
        (*inivetor) = (*vetor);
        if (isEmpty(vetor) == 1)
        {
            (*fimvetor) = NULL;
            (*inivetor) = NULL;
        }
        free(deleta);
    }
}

int main()
{
    pessoa *vetor = NULL;
    pessoa *inivetor = NULL, *fimvetor = NULL;
    

    int r, i;

    system("clear||cls");

    for (;;)
    {
        printf("0. inserir pessoa na pilha\n1. deletar pessoa da pilha\n2. listar a pilha\n3. limpar a pilha\n4. fechar programa\n");
        scanf("%d", &r);

        switch (r)
        {
        case 0: //inserir pessoa

            system("clear||cls");
            addPessoa(&vetor, &inivetor, &fimvetor);
            break;

        case 1: //deletar pessoa do topo
            system("clear||cls");
            deletaPessoa(&vetor, &inivetor, &fimvetor);
            break;

        case 2: //listar a pilha

            system("clear||cls");
            vetor = inivetor;
            while (vetor != NULL)
            {
                printf("%s, ", vetor->nome);
                printf("%d anos de idade.\n", vetor->idade);
                vetor = vetor->prox;
            }

            vetor = inivetor;
            
            break;

        case 3: //limpar a pilha

            system("clear||cls");
            while (isEmpty(&vetor) != 1)
            {
                deletaPessoa(&vetor, &inivetor, &fimvetor);
            }
            break;

        case 4: //fechar o programa

            system("clear||cls");

            free(vetor);
            exit(0);
            break;

        default:
            break;
        }
    }
}
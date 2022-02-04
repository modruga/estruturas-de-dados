#include <stdio.h>
#include <stdlib.h>

typedef struct item
{
    int cod;
} Item;

typedef struct node
{
    Item item;
    struct node *left;
    struct node *right;
} Node;

Node *initialize() //inicializa a árvore vazia
{
    return NULL;
}

Item itemCreate(int cod) //acrescenta o valor código à estrutura item
{
    Item item;
    item.cod = cod;
    return item;
}

Node *treeInsert(Node *root, Item x) //função de inserção de dados
{
    if (root == NULL)
    {
        Node *aux = (Node *)malloc(sizeof(Node));
        aux->item = x;
        aux->left = NULL;
        aux->right = NULL;
        return aux;
    }
    else
    {
        if (x.cod > root->item.cod)
        {
            root->right = treeInsert(root->right, x);
        }
        else if (x.cod < root->item.cod)
        {
            root->left = treeInsert(root->left, x);
        }
    }
    return root;
}

void treePrint(Node *root) //função recursiva de impressão de dados
{
    if (root != NULL)
    {
        printf("%d ", root->item.cod);
        treePrint(root->left);
        treePrint(root->right);
    }
}

void treeFree(Node *root) //função recursiva de liberação de memória dos nodos
{
    if (root != NULL)
    {
        treeFree(root->left);
        treeFree(root->right);
        free(root);
    }
}

Node *treeSearch(Node *root, int cod) //função de busca de um nodo específico baseado no código da estrutura interna "item"
{
    if (root != NULL)
    {
        if (root->item.cod == cod)
            return root;
        if (cod > root->item.cod)
            return treeSearch(root->right, cod);
        if (cod < root->item.cod)
            return treeSearch(root->left, cod);
    }
    return NULL;
}

Node *treeMin(Node *root) //retorna o menor nodo da maior subÁrvore
{
    if (root != NULL)
    {
        Node *aux = root;
        while (aux->left != NULL)
        {
            aux = aux->left;
        }
        return aux;
    }
}

Node *treeRemove(Node *root, int cod) //função recursiva de remoção de nodos baseada no ID do nodo
{
    if (root != NULL)
    {
        if (cod > root->item.cod)
        {
            root->right = treeRemove(root->right, cod);
        }
        else if (cod < root->item.cod)
        {
            root->left = treeRemove(root->left, cod);
        }
        else
        {
            if (root->left == NULL && root->right == NULL)
            {
                free(root);  //libera nodo encontrado
                return NULL; //informa a arvore que o ponteiro do pai do nodo removido deve ter valor nulo
            }
            else if (root->left == NULL && root->right != NULL) //se só tiver um filho à direita
            {
                Node *aux = root->right; //salva endereço do filho da direita
                free(root);              //libera o nodo encontrado
                return aux;              //informa à chamada da função que o filho da direita é o substituto
            }
            else if (root->left != NULL && root->right == NULL) //se só tiver um filho à esquerda
            {
                Node *aux = root->left; //salva o endereço do filho da esquerda
                free(root);             //libera o nodo encontrado
                return aux;             //informa à chamada da função que o filho da esquerda é o substituto
            }
            else //se tiver dois filhos
            {
                Node *aux = treeMin(root->right); //cria auxiliar que copia o enderereço do menor nodo da maior árvore
                Item itemAux = aux->item;         //insere o valor da estrutura interna item à cópia do menor nodo da maior árvore
                root = treeRemove(root, itemAux.cod);
                root->item = itemAux;
            }
        }
        return root;
    }
    return NULL;
}

int main()
{
    Node *root = initialize();
    system("clear||cls");

    for (;;)
    {
        printf("\n0. Insere nodo\n1. Remove nodo\n2. Imprime arvore\n3. Limpar e sair\n");
        int r, x;
        scanf("%d", &r);

        switch (r)
        {
        case 0:
            system("clear||cls");
            printf("insira o valor de identificacao desejado:\n");
            scanf("%d", &x);
            root = treeInsert(root, itemCreate(x));
            system("clear||cls");
            break;

        case 1:
            system("clear||cls");
            printf("insira o nodo a ser excluído:\n");
            scanf("%d", &x);
            root = treeRemove(root, x);
            system("clear||cls");
            break;

        case 2:
            system("clear||cls");
            treePrint(root);
            break;

        case 3:
            system("clear||cls");
            treeFree(root);
            exit(0);
            break;

        default:
            break;
        }
    }
}
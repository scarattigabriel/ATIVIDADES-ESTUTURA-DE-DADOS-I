#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct ttree
{
    int value;
    struct ttree *left;
    struct ttree *right;
};
typedef struct ttree tree;

tree *insertNode(tree *root, int v) // inserir novo nó
{
    tree *t, *taux, *taux_ant;
    char dir;
    t = (tree *)malloc(sizeof(tree));
    t->value = v;
    t->right = NULL;
    t->left = NULL;
    if (root == NULL) // se a arvore for vazia
    {
        return t;
    }
    taux = root;
    while (taux != NULL)
    {
        taux_ant = taux;
        if (v > taux->value)
        {
            taux = taux->right;
            dir = 'r';
        }
        else
        {
            taux = taux->left;
            dir = 'l';
        }
    }
    if (dir == 'r')
    {
        taux_ant->right = t;
    }
    else
    {
        taux_ant->left = t;
    }
    return root;
}

tree *searchNode(tree *r, int v)
{
    tree *taux = r;
    while (taux != NULL)
    {
        if (v == taux->value)
        {
            return taux; // ou break
        }
        if (v > taux->value)
        {
            taux = taux->right;
        }
        else
        {
            taux = taux->left;
        }
    }
    return taux;
}
/*
int main()
{
    tree *testTree = NULL;
    /*int op;
    while(1)
    {
        printf("0-Sair\n1-Inserir\n2-Buscar");
        scanf("%d", op);
        if(op==1)
        {
            break;
        }
        if()
    }
    testTree = insertNode(testTree, 10);
    testTree = insertNode(testTree, 5);
    testTree = insertNode(testTree, 15);
    tree *node = searchNode(testTree, 10);

    if (node != NULL)
    {
        printf("%d found\n", 10);
    }
    else
    {
        printf("%d not found\n", 10);
    }
    return 0;
}
*/

int main()
{
    tree *root = NULL;
    int qtnode;
    printf("Número de nós: ");
    scanf("%d", &qtnode);
    for (int i = 1; i < qtnode; i++)
    {
        root = insertNode(root, rand() % 100 + 1);
    }
    int key;
    printf("Chave de busca: ");
    scanf("%d", &key);
    while (key > 0)
    {
        tree *node = searchNode(root, 10);

        if (node != NULL)
        {
            printf("%d found\n", key);
        }
        else
        {
            printf("%d not found\n", key);
        }
    printf("Informe o valor a ser buscado: ");
    scanf("%d", &key);
    }
    return 0;
}
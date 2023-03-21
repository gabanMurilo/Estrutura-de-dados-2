
// A árvore B tem a propriedade de manter um balanceamento entre altura e largura, permitindo que as operações de busca e inserção tenham um desempenho eficiente.
// github.com\gabanMurilo

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define GRAU_MIN 2

typedef struct node_t
{
    int n;                    // Número de chaves armazenadas no nó
    int *keys;                // Array de chaves armazenadas no nó
    struct node_t **filhos; // Array de ponteiros para os filhos do nó
    bool folha;                // Indica se o nó é uma folha
} node_t;

// Função para criar um novo nó
node_t *novo_noh(bool folha)
{
    node_t *node = (node_t *)malloc(sizeof(node_t));
    node->n = 0;
    node->keys = (int *)malloc((2 * GRAU_MIN - 1) * sizeof(int));
    node->filhos = (node_t **)malloc(2 * GRAU_MIN * sizeof(node_t *));
    node->folha = folha;
    return node;
}

// Função para buscar uma chave na árvore B
node_t *busca(node_t *raiz, int key)
{
    int i = 0;
    while (i < raiz->n && key > raiz->keys[i])
        i++;
    if (i < raiz->n && key == raiz->keys[i])
        return raiz;
    if (raiz->folha)
        return NULL;
    return busca(raiz->filhos[i], key);
}

// Função para inserir uma chave na árvore B
void insert(node_t **raiz, int key)
{
    if (*raiz == NULL)
    {
        *raiz = novo_noh(true);
        (*raiz)->keys[0] = key;
        (*raiz)->n = 1;
    }
    else
    {
        if ((*raiz)->n == 2 * GRAU_MIN - 1)
        {
            node_t *s = novo_noh(false);
            s->filhos[0] = *raiz;
            *raiz = s;
            dividir_filho(raiz, 0, (*raiz)->filhos[0]);
            inserir_Ncheio(&(*raiz), key);
        }
        else
        {
            inserir_Ncheio(&(*raiz), key);
        }
    }
}

// Função auxiliar para inserir uma chave em um nó que não está cheio
void inserir_Ncheio(node_t **node, int key)
{
    int i = (*node)->n - 1;
    if ((*node)->folha)
    {
        while (i >= 0 && key < (*node)->keys[i])
        {
            (*node)->keys[i + 1] = (*node)->keys[i];
            i--;
        }
        (*node)->keys[i + 1] = key;
        (*node)->n++;
    }
    else
    {
        while (i >= 0 && key < (*node)->keys[i])
            i--;
        i++;
        if ((*node)->filhos[i]->n == 2 * GRAU_MIN - 1)
        {
            dividir_filho(node, i, (*node)->filhos[i]);
            if (key > (*node)->keys[i])
                i++;
        }
        inserir_Ncheio(&(*node)->filhos[i], key);
    }
}

// Função auxiliar para dividir um nó filho em dois
void dividir_filho(node_t **node, int i, node_t *child)
{
    node_t *z = novo_noh(child->folha);
    z->n = GRAU_MIN - 1;
    for (int j = 0; j < GRAU_MIN - 1; j++)
        z->keys[j] = child->keys[j + GRAU_MIN];
    // Copia os últimos GRAU_MIN filhos de child para o novo nó z, se child não for folha
    if (!child->folha)
    {
        for (int j = 0; j < GRAU_MIN; j++)
            z->filhos[j] = child->filhos[j + GRAU_MIN];
    }

    // Atualiza o número de chaves em child
    child->n = GRAU_MIN - 1;

    // Desloca os filhos de node para a direita para abrir espaço para o novo filho z
    for (int j = (*node)->n; j >= i + 1; j--)
        (*node)->filhos[j + 1] = (*node)->filhos[j];

    // Insere o novo filho z no índice i+1 de node
    (*node)->filhos[i + 1] = z;

    // Desloca as chaves de node para a direita para abrir espaço para a nova chave
    for (int j = (*node)->n - 1; j >= i; j--)
        (*node)->keys[j + 1] = (*node)->keys[j];

    // Insere a nova chave em node
    (*node)->keys[i] = child->keys[GRAU_MIN - 1];
    (*node)->n++;
}

// Função para imprimir a árvore B em ordem
void imprimirOrdenado(node_t *raiz)
{
    if (raiz != NULL)
    {
        int i;
        for (i = 0; i < raiz->n; i++)
        {
            if (!raiz->folha)
                imprimirOrdenado(raiz->filhos[i]);
            printf("%d ", raiz->keys[i]);
        }
        if (!raiz->folha)
            imprimirOrdenado(raiz->filhos[i]);
    }
}

int main()
{
    node_t *raiz = NULL;
    insert(&raiz, 10);
    insert(&raiz, 20);
    insert(&raiz, -5);
    insert(&raiz, 6);
    insert(&raiz, 12);
    insert(&raiz, -30);
    insert(&raiz, 7);
    insert(&raiz, 0);
    insert(&raiz, 17);
    insert(&raiz, 166);
    insert(&raiz, 19);

    imprimirOrdenado(raiz);

    return 0;
}
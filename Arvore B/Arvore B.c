#include <stdio.h>
#include <stdlib.h>

#define MINIMO 2
#define MAXIMO 4

typedef struct no
{
    int chaves[MAXIMO];
    struct no *filhos[MAXIMO + 1];
    int num_chaves;
    int eh_folha;
} No;

typedef struct arvore
{
    No *raiz;
    int grau_minimo;
    int grau_maximo;
} Arvore;

No *criar_no()
{
    No *n = (No *)malloc(sizeof(No));
    for (int i = 0; i <= MAXIMO; i++)
    {
        n->filhos[i] = NULL;
    }
    n->num_chaves = 0;
    n->eh_folha = 1;
    return n;
}

Arvore *criar_arvore(int grau_minimo, int grau_maximo)
{
    Arvore *arv = (Arvore *)malloc(sizeof(Arvore));
    arv->raiz = criar_no();
    arv->grau_minimo = grau_minimo;
    arv->grau_maximo = grau_maximo;
    return arv;
}

int buscar_chave(No *n, int chave)
{
    int i = 0;
    while (i < n->num_chaves && chave > n->chaves[i])
    {
        i++;
    }
    if (i < n->num_chaves && chave == n->chaves[i])
    {
        return 1;

        if (n->eh_folha)
        {
            return 0;
        }
        else
        {
            return buscar_chave(n->filhos[i], chave);
        }
    }
}

void dividir_no(Arvore *arv, No *pai, int pos_pai, No *filho)
{
    No *novo_filho = criar_no();
    novo_filho->eh_folha = filho->eh_folha;
    novo_filho->num_chaves = arv->grau_minimo - 1;
    for (int i = 0; i < arv->grau_minimo - 1; i++)
    {
        novo_filho->chaves[i] = filho->chaves[i + arv->grau_minimo];
    }
    if (!filho->eh_folha)
    {
        for (int i = 0; i < arv->grau_minimo; i++)
        {
            novo_filho->filhos[i] = filho->filhos[i + arv->grau_minimo];
        }
    }
    filho->num_chaves = arv->grau_minimo - 1;
    for (int i = pai->num_chaves; i >= pos_pai + 1; i--)
    {
        pai->filhos[i + 1] = pai->filhos[i];
    }
    pai->filhos[pos_pai + 1] = novo_filho;
    for (int i = pai->num_chaves - 1; i >= pos_pai; i--)
    {
        pai->chaves[i + 1] = pai->chaves[i];
    }
    pai->chaves[pos_pai] = filho->chaves[arv->grau_minimo - 1];
    pai->num_chaves++;
}

void inserir_nao_cheio(Arvore *arv, No *n, int chave)
{
    int i = n->num_chaves - 1;
    if (n->eh_folha)
    {
        while (i >= 0 && chave < n->chaves[i])
        {
            n->chaves[i + 1] = n->chaves[i];
            i--;
        }
        n->chaves[i + 1] = chave;
        n->num_chaves++;
    }
    else
    {
        while (i >= 0 && chave < n->chaves[i])
        {
            i--;
        }
        i++;
        if (n->filhos[i]->num_chaves == arv->grau_maximo - 1)
        {
            dividir_no(arv, n, i, n->filhos[i]);
            if (chave > n->chaves[i])
            {
                i++;
            }
        }
        inserir_nao_cheio(arv, n->filhos[i], chave);
    }
}

void inserir_chave(Arvore *arv, int chave)
{
    No *raiz = arv->raiz;
    if (raiz->num_chaves == arv->grau_maximo - 1)
    {
        No *novo_raiz = criar_no();
        arv->raiz = novo_raiz;
        novo_raiz->eh_folha = 0;
        novo_raiz->num_chaves = 0;
        novo_raiz->filhos[0] = raiz;
        dividir_no(arv, novo_raiz, 0, raiz);
        inserir_nao_cheio(arv, novo_raiz, chave);
    }
    else
    {
        inserir_nao_cheio(arv, raiz, chave);
    }
}
int main()
{
    Arvore *arv = criar_arvore(3, 5);
    inserir_chave(arv, 7);
    inserir_chave(arv, 3);
    inserir_chave(arv, 18);
    inserir_chave(arv, 2);
    inserir_chave(arv, 4);
    inserir_chave(arv, 15);
    inserir_chave(arv, 25);
    inserir_chave(arv, 11);
    inserir_chave(arv, 16);
    inserir_chave(arv, 17);
    inserir_chave(arv, 19);
    inserir_chave(arv, 21);
    imprimir_arvore(arv->raiz);
    liberar_arvore(arv);
    return 0;
}
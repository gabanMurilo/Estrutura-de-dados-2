/*
   Este algorítmo implementa uma árvore AVL, onde o usuário insere valores para uma árvore AVL e
   mostra ao usuário o número rotações feitas para cada nó.
*/

#include <stdio.h>
#include <stdlib.h>

struct no {
    int valor;
    int altura;
    int rotacoes;
    struct no *esquerda;
    struct no *direita;
};

int max(int a, int b) {
    return (a > b) ? a : b;
}

int altura(struct no *no) {
    if (no == NULL)
        return 0;
    return no->altura;
}

int fatorBalanceamento(struct no *no) {
    if (no == NULL)
        return 0;
    return altura(no->esquerda) - altura(no->direita);
}

struct no *novoNo(int valor) {
    struct no *no = (struct no *)malloc(sizeof(struct no));
    no->valor = valor;
    no->altura = 1;
    no->rotacoes = 0;
    no->esquerda = NULL;
    no->direita = NULL;
    return no;
}

struct no *rotacaoDireita(struct no *y) {
    struct no *x = y->esquerda;
    struct no *T2 = x->direita;

    x->direita = y;
    y->esquerda = T2;

    y->altura = max(altura(y->esquerda), altura(y->direita)) + 1;
    x->altura = max(altura(x->esquerda), altura(x->direita)) + 1;

    y->rotacoes += x->rotacoes + 1;
    return x;
}

struct no *rotacaoEsquerda(struct no *x) {
    struct no *y = x->direita;
    struct no *T2 = y->esquerda;

    y->esquerda = x;
    x->direita = T2;

    x->altura = max(altura(x->esquerda), altura(x->direita)) + 1;
    y->altura = max(altura(y->esquerda), altura(y->direita)) + 1;

    x->rotacoes += y->rotacoes +1;
    return y;
}

struct no *inserir(struct no *no, int valor) {
    if (no == NULL)
        return novoNo(valor);

    if (valor < no->valor)
        no->esquerda = inserir(no->esquerda, valor);
    else if (valor > no->valor)
        no->direita = inserir(no->direita, valor);
    else
        return no;

    no->altura = 1 + max(altura(no->esquerda), altura(no->direita));

    int balanceamento = fatorBalanceamento(no);

    if (balanceamento > 1 && valor < no->esquerda->valor)
        return rotacaoDireita(no);

    if (balanceamento < -1 && valor > no->direita->valor)
        return rotacaoEsquerda(no);

    if (balanceamento > 1 && valor > no->esquerda->valor) {
        no->esquerda = rotacaoEsquerda(no->esquerda);
        return rotacaoDireita(no);
    }

    if (balanceamento < -1 && valor < no->direita->valor) {
        no->direita = rotacaoDireita(no->direita);
        return rotacaoEsquerda(no);
    }

    return no;
}
void preOrder(struct no *raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->valor);
        printf("Numero de rotacoes :%d \n", raiz->rotacoes);
        preOrder(raiz->esquerda);
        preOrder(raiz->direita);
    }
}
int main() {
    struct no *raiz = NULL;
    int opcao, valor;

    while (1) {
        printf("1. Inserir um novo valor na arvore AVL\n");
        printf("2. Exibir a arvore AVL em pre-ordem\n");
        printf("0. Sair\n");
        printf("Escolha sua opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Entre com o valor: ");
                scanf("%d", &valor);
                raiz = inserir(raiz, valor);
                break;
            case 2:
                printf("Arvore AVL em pre-ordem: \n");
                preOrder(raiz);
                printf("\n");
                break;
            case 0:
                exit(0);
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    }

    return 0;
}

/*
    Este algoritimo recebe uma sequencia de valores do usuário par armazenar em uma árvore binária.
    Em seguida, mostra ao usuário cada nó e qual rotação para tornar a árvore inserida em uma árvore balanceada SPLAY. Ao final, o algoritmo
    apresenta a árvore balanceada junto com o passo-a-passo para balancear a árvore inserida.
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
  int key;
  struct node *esquerda;
  struct node *direita;
};

struct node *novono(int key) {
  struct node *node = (struct node*) malloc(sizeof(struct node));
  node->key = key;
  node->esquerda = NULL;
  node->direita = NULL;
  return node;
}

struct node *rotacao_direita(struct node *y) {
  struct node *x = y->esquerda;
  struct node *T2 = x->direita;

  x->direita = y;
  y->esquerda = T2;

  printf("Rotacao a direita com o valor %d\n", y->key);

  return x;
}

struct node *rotacao_esquerda(struct node *x) {
  struct node *y = x->direita;
  struct node *T2 = y->esquerda;

  y->esquerda = x;
  x->direita = T2;

  printf("Rotacao a esquerda com o valor %d\n", x->key);

  return y;
}

struct node *splay(struct node *raiz, int key) {
  if (raiz == NULL || raiz->key == key) {
    return raiz;
  }

  if (raiz->key > key) {
    if (raiz->esquerda == NULL) {
      return raiz;
    }

    if (raiz->esquerda->key > key) {
      raiz->esquerda->esquerda = splay(raiz->esquerda->esquerda, key);
      raiz = rotacao_direita(raiz);
    } else if (raiz->esquerda->key < key) {
      raiz->esquerda->direita = splay(raiz->esquerda->direita, key);
      if (raiz->esquerda->direita != NULL) {
        raiz->esquerda = rotacao_esquerda(raiz->esquerda);
      }
    }

    return (raiz->esquerda == NULL) ? raiz : rotacao_direita(raiz);
  } else {
    if (raiz->direita == NULL) {
      return raiz;
    }

    if (raiz->direita->key > key) {
      raiz->direita->esquerda = splay(raiz->direita->esquerda, key);
      if (raiz->direita->esquerda != NULL) {
        raiz->direita = rotacao_direita(raiz->direita);
      }
    } else if (raiz->direita->key < key) {
      raiz->direita->direita = splay(raiz->direita->direita, key);
      raiz = rotacao_esquerda(raiz);
    }

    return (raiz->direita == NULL) ? raiz : rotacao_esquerda(raiz);
  }
}

struct node *inserir(struct node *raiz, int key) {
if (raiz == NULL) {
    return novono(key);
  }

  raiz = splay(raiz, key);

  if (raiz->key == key) {
    return raiz;
  }

  struct node *node = novono(key);

  if (raiz->key > key) {
    node->direita = raiz;
    node->esquerda = raiz->esquerda;
    raiz->esquerda = NULL;
  } else {
    node->esquerda = raiz;
    node->direita = raiz->direita;
    raiz->direita = NULL;
  }

  return node;
}

void imprimirArvore(struct node *raiz, int nivel) {
if (raiz == NULL) {
return;
}
imprimirArvore(raiz->direita, nivel + 1);
for (int i = 0; i < nivel; i++) {
printf("\t");
}
printf("%d\n", raiz->key);
imprimirArvore(raiz->esquerda, nivel + 1);
}

int main() {
struct node *raiz = NULL;
int n, key;

printf("Digite o numero de elementos a ser inserido: ");
scanf("%d", &n);

printf("\nDigite o valor: ");
for (int i = 0; i < n; i++) {
scanf("%d", &key);
raiz = inserir(raiz, key);
}

printf("\nA arvore balanceada e: \n");
imprimirArvore(raiz, 0);
printf("\n");

return 0;
}

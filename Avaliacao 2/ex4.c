#include <stdio.h>
#include <stdlib.h>

typedef struct Node 
{
    int valor;
    struct Node* prox;
    struct Node* ant;
} Node;

void exibirLista(Node* topo) 
{

    Node* atual = topo;
    while (atual != NULL) {
        printf("%d   ", atual->valor);
        atual= atual->prox;
    }
    printf("\n");
}

void inserir(Node** topo, int valor) 
{
    Node* novonode = (Node*) malloc(sizeof(Node));
    novonode->valor = valor;
    novonode->ant = NULL;
    novonode->prox = *topo;
    if (*topo != NULL) {
        (*topo)->ant = novonode;
    }

    *topo = novonode;
}

void insertionSort(Node* topo) {
    Node* atual = topo;
    while (atual != NULL) {
        Node* temp = atual;
        while (temp != NULL && temp->ant!= NULL && temp->valor< temp->ant->valor) {
            int tempvalor = temp->valor;
            temp->valor = temp->ant->valor;
            temp->ant->valor = tempvalor;
            temp= temp->ant;
        }
        atual= atual->prox;
    }
}

int main() 
{
    int n, valor;
    Node* topo = NULL;
    printf("Digite o numero de elementos a ser inseridos no vetor: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("digite um numero inteiro: ");
        scanf("%d", &valor);
        inserir(&topo, valor);
    }

    printf("Antes da Ordenacao: ");
    exibirLista(topo);

    printf("\n");
    insertionSort(topo);

    printf("vetor ordenado: ");
    exibirLista(topo);

    return 0;
}

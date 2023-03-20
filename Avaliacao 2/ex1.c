#include <stdio.h>
#include <stdlib.h>

typedef struct Node 
{
    int valor;
    struct Node* prox;
} Node;

void exibirLista(Node* topo) 
{
    Node* atual = topo;
    while (atual != NULL) {
        printf("%d   ", atual->valor);
        atual = atual->prox;
    }
    printf("\n");
}

void troca(int* a, int* b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;

}

void selectionSort(Node* topo) 
{

    Node* atual = topo;
    while (atual != NULL) 
    {
        Node* maxNode = atual;
        Node* temp = atual->prox;
        while (temp != NULL) 
        {
            if (temp->valor > maxNode->valor) 
            {
                maxNode = temp;
            }
            temp = temp->prox;
        }
        if (maxNode != atual) {
            troca(&maxNode->valor, &atual->valor);
        }
        atual = atual->prox;
    }
    
}

int main() {
    Node* topo = (Node*) malloc(sizeof(Node));
    topo->valor = 8;
    topo->prox = (Node*) malloc(sizeof(Node));
    topo->prox->valor = -2;
    topo->prox->prox = (Node*) malloc(sizeof(Node));
    topo->prox->prox->valor = 91;
    topo->prox->prox->prox = (Node*) malloc(sizeof(Node));
    topo->prox->prox->prox->valor = 0;
    topo->prox->prox->prox->prox = NULL;

    printf("antes da ordenacao: ");
    exibirLista(topo);

    printf("\n");
    selectionSort(topo);

    printf("depois da ordenacao: ");
    exibirLista(topo);
    return 0;
}
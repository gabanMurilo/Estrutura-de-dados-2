// para lista duplamente encadeada
#include <stdio.h>
#include <stdlib.h>

// Estrutura de um nó da lista
typedef struct Node {
    int valor;
    struct Node* prox;
    struct Node* ant;
} Node;

// Função que adiciona um nó no final da lista
void adiciona_fim(Node** head_ref, int valor) {
    // Aloca o nó na memória
    Node* novo_no = (Node*)malloc(sizeof(Node));

    // Define o valor do nó e faz com que ele seja o último da lista
    novo_no->valor = valor;
    novo_no->prox = NULL;

    // Caso a lista esteja vazia, faz com que o novo nó seja a cabeça da lista
    if (*head_ref == NULL) {
        novo_no->ant = NULL;
        *head_ref = novo_no;
        return;
    }

    // Encontra o último nó da lista
    Node* ultimo = *head_ref;
    while (ultimo->prox != NULL) {
        ultimo = ultimo->prox;
    }

    // Adiciona o novo nó como o próximo do último nó da lista
    ultimo->prox = novo_no;
    novo_no->ant = ultimo;
}

// Função que verifica se a lista está ordenada em ordem crescente
int esta_ordenado(Node* head) {
    // Se a lista está vazia ou tem apenas um elemento, então está ordenada
    if (head == NULL || head->prox == NULL) {
        return 1;
    }

    // Percorre a lista verificando se cada elemento é menor ou igual ao próximo elemento
    Node* atual = head;
    while (atual->prox != NULL) {
        if (atual->valor > atual->prox->valor) {
            return 0;
        }
        atual = atual->prox;
    }

    return 1;
}

int main() {
    // Cria a lista com os valores 1, 3, 5, 7, 9
    Node* lista = NULL;
    adiciona_fim(&lista, 1);
    adiciona_fim(&lista, 3);
    adiciona_fim(&lista, 5);
    adiciona_fim(&lista, 7);
    adiciona_fim(&lista, 9);

    // Verifica se a lista está ordenada e imprime o resultado
    if (esta_ordenado(lista)) {
        printf("ORDENADO\n");
    } else {
        printf("NAO ORDENADO\n");
    }

    // Libera a memória alocada para a lista
    Node* atual = lista;
    while (atual != NULL) {
        Node* proximo = atual->prox;
        free(atual);
        atual = proximo;
    }

    return 0;
}

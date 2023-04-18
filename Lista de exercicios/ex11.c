#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NAIPES 4
#define VALORES 6
#define TAMANHO 24

// estrutura para representar uma carta
typedef struct {
    int valor;
    int naipe;
} Carta;

// gera um baralho de cartas ordenado
void gerarBaralho(Carta baralho[]) {
    int i, j, k = 0;
    for (i = 0; i < NAIPES; i++) {
        for (j = 0; j < VALORES; j++) {
            baralho[k].valor = j;
            baralho[k].naipe = i;
            k++;
        }
    }
}

// embaralha o baralho de cartas
void embaralharBaralho(Carta baralho[]) {
    srand(time(NULL)); // inicializa o gerador de números aleatórios
    int i, j;
    Carta temp;
    for (i = TAMANHO - 1; i > 0; i--) {
        j = rand() % (i + 1); // sorteia um índice aleatório
        temp = baralho[i];
        baralho[i] = baralho[j];
        baralho[j] = temp;
    }
}

// exibe o baralho de cartas desordenado
void exibirBaralho(Carta baralho[]) {
    int i;
    printf("Cartas do baralho (desordenado):\n");
    for (i = 0; i < TAMANHO; i++) {
        switch (baralho[i].valor) {
            case 0: printf("A"); break;
            case 1: printf("2"); break;
            case 2: printf("3"); break;
            case 3: printf("J"); break;
            case 4: printf("Q"); break;
            case 5: printf("K"); break;
        }
        switch (baralho[i].naipe) {
            case 0: printf(" de paus\n"); break;
            case 1: printf(" de ouro\n"); break;
            case 2: printf(" de copas\n"); break;
            case 3: printf(" de espada\n"); break;
        }
    }
}

void ordenarBaralho(Carta baralho[]) {
    const int n = TAMANHO;

    // criar vetores auxiliares para contar as cartas por naipe e por valor
    int countNaipe[NAIPES] = {0};
    int countValor[VALORES] = {0};

    // contar as cartas por naipe e por valor
    for (int i = 0; i < n; i++) {
        countNaipe[baralho[i].naipe]++;
        countValor[baralho[i].valor]++;
    }

    // atualizar o vetor countNaipe para que cada elemento represente a posição do último elemento de cada naipe no baralho ordenado
    for (int i = 1; i < NAIPES; i++) {
        countNaipe[i] += countNaipe[i-1];
    }

    // atualizar o vetor countValor para que cada elemento represente a posição do último elemento de cada valor no baralho ordenado
    for (int i = 1; i < VALORES; i++) {
        countValor[i] += countValor[i-1];
    }

    Carta baralhoOrdenado[TAMANHO];

    for (int i = n-1; i >= 0; i--) {
        int posicao = --countNaipe[baralho[i].naipe];
        baralhoOrdenado[posicao] = baralho[i];
    }
    for (int i = n-1; i >= 0; i--) {
        int posicao = --countValor[baralhoOrdenado[i].valor];
        baralho[posicao] = baralhoOrdenado[i];
    }
}


// menu principal
int main() {
    Carta baralho[TAMANHO];

    // gera o baralho de cartas ordenado
    gerarBaralho(baralho);

    int opcao;
    do {
        printf("\nMenu:\n");
        printf("1 - Embaralhar o baralho\n");
        printf("2 - Exibir o baralho desordenado\n");
        printf("3 - Ordenar o baralho\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                embaralharBaralho(baralho);
                printf("Baralho embaralhado!\n");
                break;
            case 2:
                exibirBaralho(baralho);
                break;
            case 3:
                ordenarBaralho(baralho);
                break;
            case 0:
                printf("\nsaindo...");
                break;
            default:
                printf("opcao invalida");
                break;
        }
    }while(opcao!=0);
}
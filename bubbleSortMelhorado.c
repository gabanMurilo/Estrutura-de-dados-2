#include "stdio.h"
#include "stdlib.h"
#include "time.h"

#define MAX 100

void bubbleSortM(int vetor[], int n)
{
    int i, j, temp;
    int troca; // Variável de controle

    for (i = 0; i < n - 1; i++)
    {
        troca = 0; // Inicializa como não trocado
        for (j = 0; j < n - i - 1; j++)
        {
            if (vetor[j] > vetor[j + 1]) // Verifica se houve trocas
            {
                temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
                troca = 1; // Altera para indicar que houve uma troca
            }
        }
        // Se não houve trocas na iteração, o vetor está ordenado e o algoritmo pode ser interrompido
        if (troca == 0)
        {
            break;
        }
    }
}

int main()
{
    int vetor[MAX];
    int n = sizeof(vetor) / sizeof(vetor[0]);
    int i, j, aux;
    printf("vetor antes da ordenacao: ");
    srand(time(NULL));
    for (i = 0; i < MAX; i++)
    {
        aux = rand() % 100 + 1;
        for (j = 0; j < MAX; j++)
        {
            if (vetor[j] == aux)
            {
                aux = rand() % 100 + 1;
                j = -1;
            }
        }
        vetor[i] = aux;
    }
    for (i = 0; i < MAX; i++)
    {
        printf("\t%d", vetor[i]);
    }
    printf("\n\n");
    bubbleSortM(vetor, n);
    printf("vetor depois da ordenacao: ");
    for (i = 0; i < MAX; i++)
    {
        printf("\t%d", vetor[i]);
    }
    printf("\n");
    return 0;  
}
#include "stdio.h"
#include "stdlib.h"
#include "time.h"

#define MAX 100

void shellSort(int vetor[], int n) {
    int gap, i, j, temp;
    // Define o espaçamento inicial
    for (gap = n/2; gap > 0; gap /= 2) {
        // Aplica o Insertion Sort nos subvetorays com o espaçamento atual
        for (i = gap; i < n; i++) {
            temp = vetor[i];
            for (j = i; j >= gap && vetor[j - gap] > temp; j -= gap) {
                vetor[j] = vetor[j - gap];
            }
            vetor[j] = temp;
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
    for (i=0; i<MAX; i++)
    {
        aux=rand() % 100 +1;
        for (j=0; j<1; j++)
        {
            if (vetor[j] == aux)
            {
                aux = rand() % 100 +1;
                j--;
            }
        }
        vetor[i]=aux;
    }
    for (i=0; i<MAX; i++)
    {
        printf("\t%d", vetor[i]);
    }
    printf("\n\n");
    shellSort(vetor, n);
    printf("vetor depois da ordenacao: ");
    for (i=0; i<MAX; i++)
    {
        printf("\t%d", vetor[i]);
    }
    printf("\n");
    return 0;
}
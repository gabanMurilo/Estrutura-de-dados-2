#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

void bubbleSort(int vetor[], int n) 
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++) 
    {
        for (j = 0; j < n - i - 1; j++) 
        {
            if (vetor[j] > vetor[j + 1]) 
            {
                temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
}


int main() 
{
    int vetor[MAX];
    int n = sizeof(vetor) / sizeof(vetor[0]);
    int i, j, aux;
    printf("vetor antes da ordanacao: ");
    srand(time(NULL)); //gera numeros aleatorios
    for (i=0; i<MAX; i++)
    {
        aux = rand() % 100 + 1; 
        for (j = 0; j < i; j++)
         {
            if (vetor[j] == aux) //verifica se o numero ja existe
            { 
                aux = rand() % 100 + 1; // Gera outro número aleatório até encontrar um que não esteja no vetor
                j = -1;
            }
         }
         vetor[i] = aux;
    }
    for (i=0; i<MAX; i++)
    {
        printf("\t%d", vetor[i]);
    }
    printf("\n\n");
    bubbleSort(vetor, n);
    printf("Vetor depois da ordenacao: ");
    for (i = 0; i < n; i++) {
        printf("\t%d", vetor[i]);
    }
    printf("\n");
    return 0;
}

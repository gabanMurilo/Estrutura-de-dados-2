#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX  100

void insertionSort(int vetor[], int n) 
{
    int i, j, key;
    for (i = 1; i < n; i++) 
    {
        key = vetor[i];
        j = i - 1;;
        while (j >= 0 && vetor[j] > key) 
        {
            vetor[j+1] = vetor[j];
            j = j - 1;
        }
        vetor[j+1] = key;
    }
}

int main() 
{
    int vetor[MAX];
    int n = sizeof(vetor) / sizeof(vetor[0]);
    int i, j, aux;

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

    printf("Vetor antes da ordenacao: \n");
    for (i = 0; i < n; i++) 
    {
        printf("%d \t", vetor[i]);
    }
    printf("\n");
    insertionSort(vetor, n);
    printf("\n Vetor depois da ordenacao: \n");
    for (i = 0; i < n; i++) 
    {
        printf("%d\t ", vetor[i]);
    }
    printf("\n");
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//ordenar um vetor em ordem descrescente

void selection_sort(int vetor[], int n) 
{
   int i, j, max_idx;
   for (i = 0; i < n-1; i++) 
   {
      max_idx = i;
      for (j = i+1; j < n; j++)
         if (vetor[j] > vetor[max_idx])
            max_idx = j;
      int temp = vetor[max_idx];
      vetor[max_idx] = vetor[i];
      vetor[i] = temp;
   }
}

int main() 
{
   int vetor[] = {64, 25, 12, 22, 11};
   int n = sizeof(vetor)/sizeof(vetor[0]);
   int i;
   printf("vetoray antes da ordenacao: \n");
   for (i = 0; i < n; i++)
      printf("%d ", vetor[i]);
   printf("\n");
   selection_sort(vetor, n);
   printf("vetoray depois da ordenacao: \n");
   for (i = 0; i < n; i++)
      printf("%d ", vetor[i]);
   printf("\n");
   return 0;
}

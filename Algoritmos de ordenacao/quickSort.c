#include <stdio.h>

void troca(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int particiona(int arr[], int inicio, int fim){
    int pivo = arr[fim];
    int i = (inicio - 1);

    for (int j = inicio; j <= fim - 1; j++){
        if (arr[j] <= pivo){
            i++;
            troca(&arr[i], &arr[j]);
        }
    }
    troca(&arr[i + 1], &arr[fim]);
    return (i + 1);
}

void quicksort(int arr[], int inicio, int fim){
    if (inicio < fim){
        int pi = particiona(arr, inicio, fim);
        quicksort(arr, inicio, pi - 1);
        quicksort(arr, pi + 1, fim);
    }
}

void imprime_vetor(int arr[], int tamanho){
    for (int i = 0; i < tamanho; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    int arr[] = {10, 7, 8, 9, 1, 5};
    int tamanho = sizeof(arr) / sizeof(arr[0]);

    printf("Vetor desordenado:\n");
    imprime_vetor(arr, tamanho);

    quicksort(arr, 0, tamanho - 1);

    printf("Vetor ordenado:\n");
    imprime_vetor(arr, tamanho);
    return 0;
}

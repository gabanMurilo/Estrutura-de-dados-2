#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int inicio, int meio, int fim){
    int i, j, k;
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    int* L = (int*) malloc(n1 * sizeof(int));
    int* R = (int*) malloc(n2 * sizeof(int));

    for (i = 0; i < n1; i++){
        L[i] = arr[inicio + i];
    }
    for (j = 0; j < n2; j++){
        R[j] = arr[meio + 1 + j];
    }

    i = 0;
    j = 0;
    k = inicio;

    while (i < n1 && j < n2){
        if (L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

void merge_sort(int arr[], int inicio, int fim){
    if (inicio < fim){
        int meio = inicio + (fim - inicio) / 2;

        merge_sort(arr, inicio, meio);
        merge_sort(arr, meio + 1, fim);

        merge(arr, inicio, meio, fim);
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

    merge_sort(arr, 0, tamanho - 1);

    printf("Vetor ordenado:\n");
    imprime_vetor(arr, tamanho);
    return 0;
}

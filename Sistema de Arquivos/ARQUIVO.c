#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    FILE *fp;
    int n, i;

    // Abrir o arquivo em modo de gravacao
    fp = fopen("numeros", "w");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }

    // Obter o número de elementos no arquivo
    fscanf(fp, "%d", &n);

    // Ler os elementos do arquivo e armazená-los em um array
    int *arr = (int*) malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        fscanf(fp, "%d", &arr[i]);
    }

    // Fechar o arquivo
    fclose(fp);

    // Ordenar o array
    bubbleSort(arr, n);

    // Abrir o arquivo em modo de gravação
    fp = fopen("numeros", "w");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }

    // Gravar o número de elementos no arquivo
    fprintf(fp, "%d\n", n);

    // Gravar os elementos ordenados no arquivo
    for (i = 0; i < n; i++) {
        fprintf(fp, "%d ", arr[i]);
    }

    // Fechar o arquivo
    fclose(fp);

    // Liberar a memória alocada para o array
    free(arr);

    printf("Arquivo ordenado e atualizado com sucesso!\n");

    return 0;
}

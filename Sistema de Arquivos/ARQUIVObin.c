#include <stdio.h>
#include <stdlib.h>

void quickSort(int arr[], int left, int right) {
    int i = left, j = right;
    int pivot = arr[(left + right) / 2];

    while (i <= j) {
        while (arr[i] < pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i <= j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }

    if (left < j) {
        quickSort(arr, left, j);
    }
    if (i < right) {
        quickSort(arr, i, right);
    }
}

int main() {
    FILE *fp;
    int n, i;

    // Abrir o arquivo em modo de escrita binária
    fp = fopen("numeros.bin", "wb");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }

    // Obter o número de elementos no arquivo
    fread(&n, sizeof(int), 1, fp);

    // Ler os elementos do arquivo e armazená-los em um array
    int *arr = (int*) malloc(n * sizeof(int));
    fread(arr, sizeof(int), n, fp);

    // Fechar o arquivo
    fclose(fp);

    // Ordenar o array
    quickSort(arr, 0, n-1);

    // Abrir o arquivo em modo de gravação binária
    fp = fopen("numeros.bin", "wb");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }

    // Gravar o número de elementos no arquivo
    fwrite(&n, sizeof(int), 1, fp);

    // Gravar os elementos ordenados no arquivo
    fwrite(arr, sizeof(int), n, fp);

    // Fechar o arquivo
    fclose(fp);

    // Liberar a memória alocada para o array
    free(arr);

    printf("Arquivo ordenado e atualizado com sucesso!\n");

    return 0;
}

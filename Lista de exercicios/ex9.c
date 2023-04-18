#include <stdio.h>
#include <stdlib.h>

void counting_sort(int *x, int n) {
    int *count, *output, max, i, j;

    // Encontra o maior elemento do vetor
    max = x[0];
    for (i = 1; i < n; i++) {
        if (x[i] > max) {
            max = x[i];
        }
    }

    // Aloca os vetores count e output
    count = (int*)calloc(max + 1, sizeof(int));
    output = (int*)malloc(n * sizeof(int));

    // Conta a frequência de cada elemento
    for (i = 0; i < n; i++) {
        count[x[i]]++;
    }

    // Soma os valores anteriores em count
    for (i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    // Coloca os elementos em suas posições corretas em output
    for (i = n - 1; i >= 0; i--) {
        output[count[x[i]] - 1] = x[i];
        count[x[i]]--;
    }

    // Copia os elementos ordenados de volta para o vetor original
    for (i = 0; i < n; i++) {
        x[i] = output[i];
    }

    // Libera a memória alocada
    free(count);
    free(output);
}

int main() {
    int x[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    int n = sizeof(x) / sizeof(x[0]);
    int i;

    counting_sort(x, n);

    printf("Vetor ordenado: ");
    for (i = 0; i < n; i++) {
        printf("%d ", x[i]);
    }
    printf("\n");

    return 0;
}

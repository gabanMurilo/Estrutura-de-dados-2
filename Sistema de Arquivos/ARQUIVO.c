#include <stdio.h>

int main() {
    int numeros[1000]; // assumindo que o arquivo terá no máximo 1000 inteiros
    int i, j, temp, n;

    // abrindo o arquivo de entrada para leitura
    FILE *entrada = fopen("numeros.txt", "r");
    if (entrada == NULL) {
        printf("Erro ao abrir o arquivo de entrada.\n");
        return 1;
    }

    // lendo os inteiros do arquivo
    n = 0;
    while (fscanf(entrada, "%d", &numeros[n]) != EOF) {
        n++;
    }

    // fechando o arquivo de entrada
    fclose(entrada);

    // ordenando os inteiros (bubble sort)
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (numeros[j] > numeros[j+1]) {
                temp = numeros[j];
                numeros[j] = numeros[j+1];
                numeros[j+1] = temp;
            }
        }
    }

    // abrindo o arquivo de saída para escrita (apaga o conteúdo anterior)
    FILE *saida = fopen("numeros.txt", "w");
    if (saida == NULL) {
        printf("Erro ao abrir o arquivo de saída.\n");
        return 1;
    }

    // escrevendo os inteiros ordenados no arquivo de saída
    for (i = 0; i < n; i++) {
        fprintf(saida, "%d\n", numeros[i]);
    }

    // fechando o arquivo de saída
    fclose(saida);

    printf("Arquivo ordenado com sucesso!\n");

    return 0;
}

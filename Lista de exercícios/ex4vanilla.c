#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);
    
    int *vetor = malloc(n * sizeof(int)); // aloca memória dinamicamente para o vetor
    if(vetor == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }
    
    printf("Digite os elementos do vetor: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &vetor[i]);
    }
    
    int ordenado = 1; // assume que o vetor está ordenado
    for(int i = 0; i < n - 1; i++) {
        if(vetor[i] > vetor[i+1]) {
            ordenado = 0; // se algum elemento estiver fora de ordem, define ordenado como 0
            break;
        }
    }
    
    if(ordenado == 1) {
        printf("ORDENADO\n");
    } else {
        printf("NAO ORDENADO\n");
    }
    
    free(vetor); // libera a memória alocada para o vetor
    
    return 0;
}

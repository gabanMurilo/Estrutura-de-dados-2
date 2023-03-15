/*
    Um dos problemas que o estudo de Estrutura de Dados procura resolver é a recuperação de informações a partir de uma estrutura.
    Neste algorítmo, temos um vetor capaz de armazenar 500 registros. 
    São adicionadas 500 registros aleatóriamente (sem repetição), e o usuário poderá buscar um registro através da busca binária.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct
{
    int id;
} Registro;

int comparar_registros(const void *a, const void *b) 
{
    Registro *x = (Registro *)a;
    Registro *y = (Registro *)b;

    return x->id - y->id;  //registro comparado em seus IDs
}

Registro *busca_binaria(Registro *vetor, int n, int id_buscado)
{
    int inicio = 0, fim = n - 1;
    while (inicio <= fim)
    {
        int meio = (inicio + fim) / 2;
        if (vetor[meio].id == id_buscado)
            return &vetor[meio];
        else if (vetor[meio].id < id_buscado)
            inicio = meio + 1;
        else
            fim = meio - 1;
    }
    return NULL;
}

int main()
{
    Registro vetor[500];
    int i, j, aux;
    int id_buscado;
    printf("vetor antes da ordenacao:\n");
    srand(time(NULL));
    for (i = 0; i < 500; i++) //preencher o vetor de forma aleatoria, com 500 registros sem repetir
    {
        aux = 0;
        int num = rand() % 500;
        for (j = 0; j < i; j++) 
        {
            if (vetor[j].id == num) 
            {
                aux = 1;
                break;
            }
        }
        if (!aux) 
        {
            vetor[i].id = num;
        } 
        else 
        {
            i--;
        }
    }
    for (i=0; i<500; i++){
        printf("%d \t", vetor[i].id);
    }
       

    qsort(vetor, 500, sizeof(Registro), comparar_registros);

    printf("\nQual registro deseja buscar? \n");
    scanf ("%d", &id_buscado);
    Registro *registro_encontrado = busca_binaria(vetor, 500, id_buscado);
    if (registro_encontrado != NULL)
    {
        printf("\nRegistro %d encontrado\n", registro_encontrado->id);

    }
    else
    {
        printf("\nRegistro nao encontrado\n"); 
    }

    return 0;
}

#include <stdio.h>
#include <string.h>

#define MAX_NOMES 100
#define TAM_NOME 50

char nomes[MAX_NOMES][TAM_NOME];
int num_nomes = 0;
int ordenado = 0;

void adicionar_nome()
{
    char nome[TAM_NOME];
    printf("Digite o nome a ser adicionado: ");
    fflush(stdin);
    fgets(nome, 50, stdin);
    strcpy(nomes[num_nomes], nome);
    num_nomes++;
    ordenado = 0;
}

void exibir_nomes()
{
    printf("Nomes cadastrados:\n");
    for (int i = 0; i < num_nomes; i++)
    {
        printf("%d: %s\n", i + 1, nomes[i]);
    }
}

void selection_sort()
{
    for (int i = 0; i < num_nomes - 1; i++)
    {
        int pos_menor = i;
        for (int j = i + 1; j < num_nomes; j++)
        {
            if (strcmp(nomes[j], nomes[pos_menor]) < 0)
            {
                pos_menor = j;
            }
        }
        if (pos_menor != i)
        {
            char aux[TAM_NOME];
            strcpy(aux, nomes[i]);
            strcpy(nomes[i], nomes[pos_menor]);
            strcpy(nomes[pos_menor], aux);
        }
    }
    ordenado = 1;
}

void bubble_sort()
{
    int trocou;
    do
    {
        trocou = 0;
        for (int i = 0; i < num_nomes - 1; i++)
        {
            if (strcmp(nomes[i], nomes[i + 1]) > 0)
            {
                char aux[TAM_NOME];
                strcpy(aux, nomes[i]);
                strcpy(nomes[i], nomes[i + 1]);
                strcpy(nomes[i + 1], aux);
                trocou = 1;
            }
        }
    } while (trocou);
    ordenado = 1;
}

int buscar_nome(char *nome)
{
    if (num_nomes == 0)
    {
        return -2;
    }
    if (!ordenado)
    {
        for (int i = 0; i < num_nomes; i++)
        {
            if (strcmp(nomes[i], nome) == 0)
            {
                return i;
            }
        }
        return -1;
    }
    else
    {
        int inicio = 0;
        int fim = num_nomes - 1;
        while (inicio <= fim)
        {
            int meio = (inicio + fim) / 2;
            int cmp = strcmp(nomes[meio], nome);
            if (cmp == 0)
            {
                return meio;
            }
            else if (cmp < 0)
            {
                inicio = meio + 1;
            }
            else
            {
                fim = meio - 1;
            }
        }
        return -1;
    }
}

int main()
{
    char nome[TAM_NOME];
    int opcao;
    do
    {
        printf("\n\n");
        printf("1. Adicionar nome\n");
        printf("2. Exibir nomes\n");
        printf("3. Ordenar nomes (Selection Sort)\n");
        printf("4. Ordenar nomes (Bubble Sort)\n");
        printf("5. Buscar nome\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            adicionar_nome();
            break;
        case 2:
            exibir_nomes();
            break;
        case 3:
            selection_sort();
            break;
        case 4:
            bubble_sort();
            break;
        case 5:
            printf("Digite o nome a ser buscado: ");
            fflush(stdin);
            fgets(nome, 50, stdin);
            int pos = buscar_nome(nome);
            if (pos == -1)
            {
                printf("Nome nao encontrado.\n");
            }
            else if (pos == -2)
            {
                printf("Nenhum nome cadastrado.\n");
            }
            else
            {
                printf("Nome encontrado na posicao %d.\n", pos + 1);
            }
            break;
        case 0:
            printf("saindo...");
            break;
        default:
            printf("opcao invalida \n");
            break;
        }
    } while (opcao != 0);
    return 0;
}
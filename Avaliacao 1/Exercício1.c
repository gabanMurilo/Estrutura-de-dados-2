/*  
    Este algoritmo recebe do usuário informações sobre Filmes, sendo elas: Título, codigo de identificação, gênero, nome do diretor, país de origem e
    sua nota no IMDb.
    Os dados são armazenados em uma estrutura estática linear. Além de inserir o filme, o usuário será capaz de: buscar por código ou nome (podendo ser por
    busca binária ou sequencial), editar as informações do filme e listar o acervo.

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILMES 100 //limitar o numero de filmes cadastrados
struct Filme
{
    char nome[50];
    int codigo;
    char genero[20];
    char diretor[25];
    char pais[20];
    float notaimdb;
};

int buscaBinariaCodigo(const struct Filme *filmes, int quantidade, int codigo)
{
    int esquerda = 0, direita = quantidade - 1, meio;

    while (esquerda <= direita)
    {
        meio = (esquerda + direita) / 2;
        if (filmes[meio].codigo == codigo)
        {
            return meio;
        }
        else if (filmes[meio].codigo < codigo)
        {
            esquerda = meio + 1;
        }
        else
        {
            direita = meio - 1;
        }
    }

    return -1;

}

int buscaSequencialCodigo(const struct Filme *filmes, int quantidade, int codigo)
{
    int i;
    for (i = 0; i < quantidade; i++)
    {
        if (filmes[i].codigo == codigo)
        {
            return i;
        }
    }

    return -1;

}

int buscaSequencialNome(const struct Filme *filmes, int quantidade, char *nome) {
for (int i = 0; i < quantidade; i++) {
if (strcmp(filmes[i].nome, nome) == 0) {
return i;
}
}
return -1;
}

int buscaBinariaNome(const struct Filme *filmes, int quantidade, char *nome) {
int inicio = 0, fim = quantidade - 1, meio;
while (inicio <= fim) {
meio = (inicio + fim) / 2;
int resultado = strcmp(filmes[meio].nome, nome);
if (resultado == 0) {
return meio;
}
if (resultado < 0) {
inicio = meio + 1;
} else {
fim = meio - 1;
}
}
return -1;
}

void inserirFilme(struct Filme *filmes, int *quantidade)
{

    if (*quantidade == MAX_FILMES)
    {
        printf("Limite maximo de filmes atingido.\n");
        return;
    }
    printf("Escreva o titulo do filme: ");
    fflush(stdin);
    fgets(filmes[*quantidade].nome, 50, stdin);

    printf("Insira o codigo de identificacao do filme: ");
    fflush(stdin);
    scanf("%d", &filmes[*quantidade].codigo);

    printf("Escreva o genero do filme: ");
    fflush(stdin);
    fgets(filmes[*quantidade].genero, 20, stdin);

    printf("escreva o nome do diretor do filme: ");
    fflush(stdin);
    fgets (filmes[*quantidade].diretor, 25, stdin);

    printf("Escreva o pais de origem: ");
    fflush(stdin);
    fgets(filmes[*quantidade].pais, 20, stdin);

    do{
    printf("Digite a nota IMDB: ");
    fflush(stdin);
    scanf("%f", &filmes[*quantidade].notaimdb);
    if (filmes[*quantidade].notaimdb>10){
        printf("impossivel uma nota maior que 10! \n");
    }
     if (filmes[*quantidade].notaimdb<0){
        printf("impossivel uma nota menor que 0! \n");
    }
    } while (filmes[*quantidade].notaimdb>10 || filmes[*quantidade].notaimdb<0);
    (*quantidade)++;
}


void buscarFilmePorCodigo(const struct Filme *filmes, int quantidade)

{
    int codigo, posicao;

    printf("Insira o codigo de identificacao do filme: ");

    scanf("%d", &codigo);

    printf("Qual o metodo de busca?\n 1 - binaria \n2 - sequencial): \n");
    int opcao;
    scanf("%d", &opcao);

    if (opcao == 1)
    {
        posicao = buscaBinariaCodigo(filmes, quantidade, codigo);
    }
    else if (opcao == 2)
    {
        posicao = buscaSequencialCodigo(filmes, quantidade, codigo);
    }
    else
    {
        printf("Opcao invalida.\n");
        return;
    }

    if (posicao == -1)
    {
        printf("O filme com o codigo %d nao foi encontrado.\n", codigo);
    }
    else
    {
        printf("Filme %s encontrado: \n", filmes[posicao].nome);

        printf("Codigo: %d\n", filmes[posicao].codigo);
        printf("Genero: %s\n", filmes[posicao].genero);
        printf("Diretor: %s\n", filmes[posicao].diretor);
        printf("Pais de origem: %s\n", filmes[posicao].pais);
        printf("Nota IMDb: %.2f\n", filmes[posicao].notaimdb);
    }

}



void buscarFilmePorNome(const struct Filme *filmes, int quantidade)

{
    char nome[40];
    int posicao;

    printf("Insira o nome do filme: ");
    fflush(stdin);
    fgets(nome, 40, stdin);

    printf("Qual o metodo de busca?\n 1 - binaria \n2 - sequencial): \n");
    int opcao;
    scanf("%d", &opcao);

    if (opcao == 1)
    {
        posicao = buscaBinariaNome(filmes, quantidade, nome);
    }
    else if (opcao == 2)
    {
        posicao = buscaSequencialNome(filmes, quantidade, nome);
    }
    else
    {
        printf("Opcao invalida.\n");
        return;
    }

    for (posicao = 0; posicao < quantidade; posicao++)
    {
        if (strcmp(nome, filmes[posicao].nome) != 0)
        {
            printf("O filme %s nao foi encontrado.\n", nome);
        }
        else
        {
            printf("Filme %s encontrado:\n", filmes[posicao].nome);

            printf("Codigo: %d\n", filmes[posicao].codigo);
            printf("Genero: %s\n", filmes[posicao].genero);
            printf("Diretor: %s\n", filmes[posicao].diretor);
            printf("Pais de origem: %s\n", filmes[posicao].pais);
            printf("Nota IMDb: %.2f\n", filmes[posicao].notaimdb);
        }
    }

}



void editarFilme(struct Filme *filmes, int quantidade)
{
    int codigo, posicao;

    printf("Insira o codigo do filme que deseja editar: ");
    scanf("%d", &codigo);

    posicao = buscaSequencialCodigo(filmes, quantidade, codigo);
    if (posicao == -1)
    {
        printf("Filme nao encontrado.\n");
        return;
    }
    printf("Digite o novo titulo: ");
    fflush(stdin);
    fgets(filmes[posicao].nome, 50, stdin);
    printf("Digite o novo codigo do filme: ");
    fflush(stdin);
    scanf("%d", &filmes[posicao].codigo);
    fflush(stdin);
    printf("Insira o novo genero do filme: ");
    fflush(stdin);
    fgets(filmes[posicao].genero, 20, stdin);
    fflush(stdin);
    printf("Insira o novo diretor do filme: ");
    fflush(stdin);
    fgets(filmes[posicao].diretor, 25, stdin);
    fflush(stdin);
    printf("Insira o novo pais de origem do filme: ");
    fflush(stdin);
    fgets(filmes[posicao].pais, 20, stdin);
    
    do{
    printf("Insira a nova nota IMDb do filme: ");
    fflush(stdin);
    scanf("%f", &filmes[posicao].notaimdb);
    if(filmes[posicao].notaimdb>10){
        printf("Impossivel nota maior que 10!\n");
    }
    if(filmes[posicao].notaimdb<10){
        printf("Impossivel nota menor que 0!\n");
}

    }while (filmes[posicao].notaimdb>10 || filmes[posicao].notaimdb<0);

    printf("Filme editado com sucesso.\n");

}

void listarArcevo(const struct Filme *filmes, int quantidade)
{
    int i;

    printf("LISTA DE FILMES:\n");
    for (i = 0; i < quantidade; i++)
    {
        printf ("TITULO: %s\n", filmes[i].nome);
        printf ("CODIGO: %d\n", filmes[i].codigo);
        printf ("GENERO: %s\n", filmes[i].genero);
        printf ("DIRETOR: %s\n", filmes[i].diretor);
        printf ("PAIS: %s\n", filmes[i].pais);
        printf ("NOTA: %.2f\n", filmes[i].notaimdb);
    }

}


  int main()
{
    struct Filme filmes[MAX_FILMES];
    int quantidade = 0;
    int opcao;

    while (1)
    {
        printf("\n1. Inserir filme\n");
        printf("2. Buscar filme por codigo\n");
        printf("3. Buscar filme por nome\n");
        printf("4. Editar filme\n");
        printf("5. Listar acervo\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: \n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            inserirFilme(filmes, &quantidade);
            break;
        case 2:
            buscarFilmePorCodigo(filmes, quantidade);
            break;
        case 3:
            buscarFilmePorNome(filmes, quantidade);
            break;
        case 4:
            editarFilme(filmes, quantidade);
            break;
        case 5:
            listarArcevo(filmes, quantidade);
            break;
        case 0:
            return 0;
        default:
            printf("Opcao invalida\n");
            break;
        }
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_TABELA 1000 // tamanho da tabela hash
#define TAMANHO_CHAVE 50    // tamanho máximo da chave

// estrutura para armazenar uma chave-valor
typedef struct
{
    char chave[TAMANHO_CHAVE];
    int valor;
} ParChaveValor;

// estrutura para armazenar um nó da lista ligada
typedef struct NoLista
{
    ParChaveValor par;
    struct NoLista *prox;
} NoLista;

// função hash simples que retorna um valor hash baseado na chave
unsigned int hash(char *chave)
{
    unsigned int valor = 0;
    int i;
    for (i = 0; i < strlen(chave); i++)
    {
        valor += chave[i];
    }
    return valor % TAMANHO_TABELA;
}

// função para inserir um par chave-valor na tabela hash
void inserir(NoLista **tabela, char *chave, int valor)
{
    // obter o índice hash para a chave
    unsigned int indice = hash(chave);

    // criar um novo nó para a lista ligada
    NoLista *novoNo = (NoLista *)malloc(sizeof(NoLista));
    strcpy(novoNo->par.chave, chave);
    novoNo->par.valor = valor;
    novoNo->prox = NULL;

    // adicionar o novo nó à lista ligada
    if (tabela[indice] == NULL)
    {
        tabela[indice] = novoNo;
    }
    else
    {
        NoLista *atual = tabela[indice];
        while (atual->prox != NULL)
        {
            atual = atual->prox;
        }
        atual->prox = novoNo;
    }
}

// função para buscar um valor na tabela hash a partir de uma chave
int buscar(NoLista **tabela, char *chave)
{
    // obter o índice hash para a chave
    unsigned int indice = hash(chave);

    // buscar a chave na lista ligada
    NoLista *atual = tabela[indice];
    while (atual != NULL)
    {
        if (strcmp(atual->par.chave, chave) == 0)
        {
            return atual->par.valor;
        }
        atual = atual->prox;
    }

    // chave não encontrada
    return -1;
}

int main()
{
    // criar a tabela hash
    NoLista *tabela[TAMANHO_TABELA];
    int i;
    for (i = 0; i < TAMANHO_TABELA; i++)
    {
        tabela[i] = NULL;
    }

    // inserir alguns pares chave-valor na tabela hash
    inserir(tabela, "chave1", 10);
    inserir(tabela, "chave2", 20);
    inserir(tabela, "chave3", 30);
    inserir(tabela, "chave4", 40);

    printf("Valor para chave1: %d\n", buscar(tabela, "chave1"));
    printf("Valor para chave2: %d\n", buscar(tabela, "chave2"));
    printf("Valor para chave3: %d\n", buscar(tabela, "chave3"));
    printf("Valor para chave4: %d\n", buscar(tabela, "chave4"));

    // liberar a memória alocada para a tabela hash
    for (i = 0; i < TAMANHO_TABELA; i++)
    {
        NoLista *atual = tabela[i];
        while (atual != NULL)
        {
            NoLista *prox = atual->prox;
            free(atual);
            atual = prox;
        }
    }

    return 0;
}

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

// estrutura para armazenar a tabela hash
typedef struct
{
    NoLista **tabela;
    int tamanho;
} TabelaHash;

// função hash simples que retorna um valor hash baseado na chave
unsigned int hash(char *chave, int tamanhoTabela)
{
    unsigned int valor = 0;
    int i;
    for (i = 0; i < strlen(chave); i++)
    {
        valor += chave[i];
    }
    return valor % tamanhoTabela;
}

// função para criar uma nova tabela hash com o tamanho especificado
TabelaHash *criarTabelaHash(int tamanho)
{
    TabelaHash *tabelaHash = (TabelaHash *)malloc(sizeof(TabelaHash));
    tabelaHash->tabela = (NoLista **)calloc(tamanho, sizeof(NoLista *));
    tabelaHash->tamanho = tamanho;
    return tabelaHash;
}

// função para liberar a memória alocada para a tabela hash
void liberarTabelaHash(TabelaHash *tabelaHash)
{
    int i;
    for (i = 0; i < tabelaHash->tamanho; i++)
    {
        NoLista *atual = tabelaHash->tabela[i];
        while (atual != NULL)
        {
            NoLista *prox = atual->prox;
            free(atual);
            atual = prox;
        }
    }
    free(tabelaHash->tabela);
    free(tabelaHash);
}

// função para inserir um par chave-valor na tabela hash
void inserir(TabelaHash *tabelaHash, char *chave, int valor)
{
    // obter o índice hash para a chave
    unsigned int indice = hash(chave, tabelaHash->tamanho);

    // criar um novo nó para a lista ligada
    NoLista *novoNo = (NoLista *)malloc(sizeof(NoLista));
    strcpy(novoNo->par.chave, chave);
    novoNo->par.valor = valor;
    novoNo->prox = NULL;

    // adicionar o novo nó à lista ligada
    if (tabelaHash->tabela[indice] == NULL)
    {
        tabelaHash->tabela[indice] = novoNo;
    }
    else
    {
        NoLista *atual = tabelaHash->tabela[indice];
        while (atual->prox != NULL)
        {
            atual = atual->prox;
        }
        atual->prox = novoNo;
    }
}

// função para buscar um valor na tabela
int buscar(TabelaHash *tabelaHash, char *chave)
{
    // obter o índice hash para a chave
    unsigned int indice = hash(chave, tabelaHash->tamanho);
    // percorrer a lista ligada no índice correspondente
    NoLista *atual = tabelaHash->tabela[indice];
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

// função principal para teste
int main()
{
    TabelaHash *tabela = criarTabelaHash(TAMANHO_TABELA);
    // inserir alguns valores na tabela hash
    inserir(tabela, "chave1", 10);
    inserir(tabela, "chave2", 20);
    inserir(tabela, "chave3", 30);
    inserir(tabela, "chave4", 40);

    // buscar alguns valores na tabela hash
    printf("Valor para chave1: %d\n", buscar(tabela, "chave1"));
    printf("Valor para chave2: %d\n", buscar(tabela, "chave2"));
    printf("Valor para chave3: %d\n", buscar(tabela, "chave3"));
    printf("Valor para chave4: %d\n", buscar(tabela, "chave4"));

    // liberar a memória alocada para a tabela hash
    liberarTabelaHash(tabela);
    return 0;
}

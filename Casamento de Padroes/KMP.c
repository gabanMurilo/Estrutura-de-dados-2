#include <stdio.h>
#include <string.h>

void buscaKMP(char *padrao, char *texto, int *tabela)// função que que recebe o padrão a ser procurado e a string de entrada
{
    int i, j, m, n;
    m = strlen(padrao);
    n = strlen(texto);
    i = j = 0;
    while (j < n)
    {
        if (padrao[i] == texto[j])
        {
            i++;
            j++;
        }
        if (i == m) {
            printf("Padrao encontrado na posicao %d do texto. \n", j - i+1);
            i = tabela[i - 1];
        } else if (j < n && padrao[i] != texto[j]) {
            if (i != 0)
                i = tabela[i - 1];
            else
                j = j + 1;
        }
    }
}

void computePSarray(char *padrao, int m, int *tabela) // funcao usada para criar o array de valores de prefixo/sufixo do padrão.
{
    int len = 0;
    int i;
    tabela[0] = 0;
    i = 1;
    while (i < m)
    {
        if (padrao[i] == padrao[len])
        {
            len++;
            tabela[i] = len;
            i++;
        } else
        {
            if (len != 0) {
                len = tabela[len - 1];
            } else
            {
                tabela[i] = 0;
                i++;
            }
        }
    }
}

int main()
{
    char texto[100], padrao[100];
    int tabela[100];
    printf("Digite o texto: ");
    gets(texto);
    printf("Digite o padrao: ");
    gets(padrao);
    computePSarray(padrao, strlen(padrao), tabela);
    buscaKMP(padrao, texto, tabela);
    return 0;
}
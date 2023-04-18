#include "stdio.h"
#include "string.h"

void buscaForcaBruta(char *padrao, char *texto)
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
            i = 0;
        } else if (j < n && padrao[i] != texto[j]) {
            if (i != 0)
                i = 0;
            else
                j = j + 1;
        }
    }
}

int main()
{
    char texto[100], padrao[100];
    printf("Digite o texto: ");
    gets(texto);
    printf("Digite o padrao: ");
    gets(padrao);
    buscaForcaBruta(padrao, texto);
    return 0;
}


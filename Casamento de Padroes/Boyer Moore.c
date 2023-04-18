#include "stdio.h"
#include "string.h"

int max(int a, int b)
{
    return (a > b) ? a : b;
}

void badCharheuristic(char *str, int size, int badchar[256])
{
    int i;
    for (i = 0; i < 256; i++)
        badchar[i] = -1;
    for (i = 0; i < size; i++)
        badchar[(int) str[i]] = i;
}

void search(char *txt, char *pat)
{
    int m = strlen(pat);
    int n = strlen(txt);
    int badchar[256];
    badCharheuristic(pat, m, badchar);
    int s = 0;
    while (s <= (n - m))
    {
        int j = m - 1;
        while (j >= 0 && pat[j] == txt[s + j])
            j--;
        if (j < 0)
        {
            printf("Padrao encontrado na posicao %d do texto. \n", s + 1);
            s += (s + m < n) ? m - badchar[txt[s + m]] : 1;
        } else
            s += max(1, j - badchar[txt[s + j]]);
    }
}

int main()
{
    char texto[100], padrao[100];
    printf("Digite o texto: ");
    gets(texto);
    printf("Digite o padrao: ");
    gets(padrao);
    search(texto, padrao);
    return 0;
}

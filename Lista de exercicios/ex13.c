#include <stdio.h>
#include <string.h>

void quicksort(char *string, int left, int right);
int compara(char a, char b);

int main() {
    char string[50];

    printf("Digite uma string: ");
    scanf("%s", string);

    quicksort(string, 0, strlen(string) - 1);

    printf("A string ordenada em ordem decrescente: %s\n", string);

    return 0;
}

void quicksort(char *string, int left, int right) {
    if (left < right) {
        int i = left, j = right;
        char pivot = string[(left + right) / 2];

        while (i <= j) {
            while (compara(string[i], pivot) > 0) {
                i++;
            }

            while (compara(string[j], pivot) < 0) {
                j--;
            }

            if (i <= j) {
                char temp = string[i];
                string[i] = string[j];
                string[j] = temp;
                i++;
                j--;
            }
        }

        quicksort(string, left, j);
        quicksort(string, i, right);
    }
}

int compara(char a, char b) {
    if (a < b) {
        return 1;
    } else if (a > b) {
        return -1;
    } else {
        return 0;
    }
}

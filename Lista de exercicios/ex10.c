#include <stdio.h>

int verificaArrumado(int v[], int p, int r) {
    int j;
    
    for (j = p+1; j <= r-1; j++) {
        if (v[j] > v[j-1] && v[j] < v[j+1]) {
            return j;
        }
    }
    
    return -1;
}

int main() {
    int v[] = {1, 2, 3, 4, 5, 6};
    int p = 0;
    int r = 5;
    
    int j = verificaArrumado(v, p, r);
    
    if (j == -1) {
        printf("O vetor nao esta arrumado\n");
    } else {
        printf("O vetor esta arrumado e j = %d\n", j);
    }
    
    return 0;
}

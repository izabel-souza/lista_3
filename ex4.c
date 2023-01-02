#include <stdio.h> <stdlib.h>

int divs(int n, int *max, int *min);

int main (void) {

    int n, max, min, resultado;
    do {
        printf("Informe n: ");
        scanf("%d", &n);
    } while (n < 0);

    resultado = divs(n, &max, &min);

    if(resultado != 0) {
        printf("%d = numero composto\nMaximo divisor = %d\n Minimo divisor = %d", n, max, min);
    }
    else {
        printf("%d =  numero composto", n);
    }

    return 0;
}

int divs(int n, int *max, int *min){
    
    for(int i = 2; i < n; i++) {
        if (n % i == 0) {
            *max = i;
        }
    }
    for(int i = n; i > 1; i--) {
        if (n % i == 0) {
            *min = i;
        }
    }

    int divisores = 0;
    for(int i = 1; i <= n; i++) {
        if (n % i == 0) {
            divisores++;
        }
    }

    if (divisores == 2) {
        return 0;
    }
    else {
        return 1;
    }
}
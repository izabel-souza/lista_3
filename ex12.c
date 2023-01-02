#include <stdio.h> <stdlib.h> <conio.h>
#define MAX 80

int main (void) {

    char vetor[MAX], caractere;
    int contador = 0;

    for(int i = 0; i < MAX; i++) {
        printf("Informe um caractere: ");
        caractere = getch();
        if(caractere == '\r') {
            break;
        }
        vetor[i] = caractere;
        contador++;
    }

    for(int i = 0; i < contador; i++) {
        if(vetor[i] == ' ') {
            printf("\n");
            i++;
        }
        printf("%c", vetor[i]);
    }

    return 0;
}
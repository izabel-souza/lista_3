#include <stdio.h> <stdlib.h>

int *criacao_vetor(int n);
void impressao_vetor(int n, int *vet);
int maiores(int n, int *vet, int x);

int main (void) {

    int n, x, n_maiores;
    int *vetor;
    do {
        printf("Informe a quantidade de numeros no vetor e informe x: ");
        scanf("%d %d", &n, &x);
    } while ((n < 0) || (x < 0));

    vetor = criacao_vetor(n);
    n_maiores = maiores(n, vetor, x);
    impressao_vetor(n, vetor);
    printf("\nTem %d numero(s) maior(es) que %d no vetor", n_maiores, x);
    free(vetor);

    return 0;
}

int *criacao_vetor(int n) {

    int *vet;
    vet = (int *) malloc(n * sizeof(int));
    if(vet == NULL) { printf("Falta de memoria"); exit(1); }

    for(int i = 0; i < n; i++) {
        printf("Informe elemento %d do vetor: ", i+1);
        scanf("%d", &vet[i]);
    }
    return vet;
}

void impressao_vetor(int n, int *vet) {
    for(int i = 0; i < n; i++) {
        printf("%d, ", vet[i]);
    }
}

int maiores(int n, int * vet, int x) {

    int n_maiores = 0;
    for(int i = 0; i < n; i++) {
        if(vet[i] > x) {
            n_maiores++;
        }
    }
    return n_maiores;
}
#include <stdio.h> <stdlib.h>

float *criacao_vetor(int n);
float max_vetor(int n, float *vet);
int main (void) {

    int n; 
    float *vetor;
    float max_valor;
    do {
        printf("Informe a quantidade de numeros no vetor: ");
        scanf("%d", &n);
    } while (n < 0);

    vetor = criacao_vetor(n);
    max_valor = max_vetor(n, vetor);
    printf("Maior valor do vetor = %.2f", max_valor);
    free(vetor);

    return 0;
}

float *criacao_vetor(int n) {

    float *vet;
    vet = (float *) malloc(n * sizeof(float));
    if (vet == NULL) { printf("Falta de memoria"); exit(1); }

    for(int i = 0; i < n; i++) {
        printf("Informe %d elemento: ", i+1);
        scanf("%f", &vet[i]);
    }

    return vet;
}

float max_vetor(int n, float *vet) {

    float max = vet[0];

    for(int i = 1; i < n; i++) {
        if(vet[i] > max) {
            max = vet[i];
        }
    }
    return max;
}

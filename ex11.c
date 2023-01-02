#include <stdio.h> <stdlib.h>

typedef struct info {
    int idade;
    float altura;
    int sexo;
} Info;

void criacao_vetor(int n, Info **vet);
void analise(int n, Info **vet);

int main (void) {

    int n;
    do {
        printf("Informe o numero de pessoas: ");
        scanf("%d", &n);
    } while (n < 0);

    Info **vetor = (Info **) malloc(n * sizeof(Info*));
    if(vetor == NULL) { printf("Falta de memoria"); exit(1); }
    criacao_vetor(n, vetor);
    impressao(n, vetor);
    analise(n, vetor);

    return 0;
}

void criacao_vetor(int n, Info **vet) {

    for(int i = 0; i < n; i++) {
        vet = (Info *) malloc(sizeof(Info));
        printf("Informe idade: ");
        scanf("%d", &vet[i]->idade);
        printf("Informe altura: ");
        scanf("%f", &vet[i]->altura);
        printf("Informe 1 para masculino e 2 para feminino: ");
        scanf("%d", &vet[i]->sexo);
    }

}

void analise(int n, Info **vet) {

    int n_mulheres = 0, n_homens = 0;
    for(int i = 0; i < n; i++) {
        if((vet[i]-> sexo == 2) && ((vet[i]-> idade >= 20 && vet[i]->idade <= 35))) {
            n_mulheres++;
        }
        else if((vet[i]->sexo == 1) &&(vet[i]->altura > 1.8)) {
            n_homens++;
        }
    }

    printf("Numero de mulheres com idade entre 20 e 35 anos = %d\n", n_mulheres);
    printf("Numero de homens com altura maior que 1.80m = %d", n_homens);

}

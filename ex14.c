#include <stdio.h> <stdlib.h> <string.h>
#define MAX 100
#define TAMANHO 10

typedef struct quest {
    int idade;
    char opiniao[TAMANHO];
} Quest;

void preenchimento(int n, Quest **vetor);
void analise(int n, Quest **vetor);
void free_vetor(int n, Quest **vetor);

int main (void) {

    int n;
    do {
        printf("Informe a quantidade de pessoas: ");
        scanf("%d", &n);
    } while ((n < 0) || (n > MAX));

    Quest **vetor =  (Quest *) malloc(n * sizeof(Quest));
    if(vetor == NULL) { printf("Falta de memoria"); exit(1); }
    preenchimento(n, vetor);
    analise(n, vetor);
    free_vetor(n, vetor);

    return 0;
}

void preenchimento(int n, Quest **vetor) {
    for(int i = 0; i < n; i++){
        vetor[i] = (Quest *) malloc(sizeof(Quest));
        printf("Informe a idade do %d individuo: ", i+1);
        scanf("%d", &vetor[i]->idade);
        printf("Informe a opiniao do %d individuo: ", i+1);
        scanf(" %9[^\n]%c", vetor[i]->opiniao);
    }
}

void analise(int n, Quest **vetor) {
    
    int resp_otimo = 0, resp_bom = 0, resp_regular = 0, resp_pessimo = 0, media_idade_ruim = 0, maior_idade_pessimo = vetor[0]->idade, maior_idade_ruim = vetor[0]->idade, maior_idade_otimo = vetor[0]->idade;
    for(int i = 0; i < n; i++) {
        if(vetor[i]->opiniao == "otimo") {
            resp_otimo++;
            if(vetor[i]->idade > maior_idade_otimo) {
                maior_idade_otimo = vetor[i]->idade;
            }
        }
        if(vetor[i]->opiniao == "bom") {
            resp_bom++;
        }
        if(vetor[i]->opiniao == "regular") {
            resp_regular++;
        }
        if(vetor[i]->opiniao == "pessimo") {
            resp_pessimo++;
            if(vetor[i]->idade > maior_idade_pessimo) {
                maior_idade_pessimo = vetor[i]->idade;
            }
        }
        if(vetor[i]->opiniao == "ruim") {
            media_idade_ruim++;
            if(vetor[i]->idade > maior_idade_ruim) {
                maior_idade_ruim = vetor[i]->idade;
            }
        }
    }
    
    printf("N de respostas otimo = %d", resp_otimo);
    int percent_bomregular = ((resp_bom/100)-(resp_regular/100));
    printf("Diferenca percentual entre respostas bom e regular = %d", percent_bomregular);
    media_idade_ruim /= n;
    printf("Media de idade das pessoas que responderam ruim = %d", media_idade_ruim);
    int percent_pessimo = (resp_pessimo/100);
    printf("Porcentagem de respostas péssimo = %d\nA maior idade que utilizou esta opcao = %d", percent_pessimo, maior_idade_pessimo);

}

void free_vetor(int n, Quest **vetor) {
    for(int i = 0; i < n; i++) {
        if(vetor[i] != NULL) {
            free(vetor[i]);
            vetor[i] = NULL;
        }
    }
}
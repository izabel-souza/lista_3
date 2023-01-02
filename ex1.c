#include <stdio.h> <stdlib.h> <string.h>
#define PI 3.14159265

void calc_circulo(float r, float *circunferencia, float *area);

int main (void) {

    float raio, circunferencia, area;
    do {
        printf("Informe o raio do circulo: ");
        scanf("%f", &raio);
    } while (raio < 0);

    calc_circulo(raio, &circunferencia, &area);
    printf("Area = %f\nCircunferencia = %f", area, circunferencia);

    return 0;
}

void calc_circulo(float r, float *circunferencia, float *area) {
    *area = (PI * (r*r));
    *circunferencia = (2 * PI * r);
}
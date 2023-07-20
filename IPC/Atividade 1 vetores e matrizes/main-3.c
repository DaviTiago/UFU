#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//Davi Tiago Soares. Numero de matricula: 12211BSI240, Matheus Soares Costa. Numero de matricula: 12211BSI215

int main() {
    int n;
    float soma=0, s;
    printf("Quantos valores deseja ler? ");
    scanf("%d", &n);
    float vetor[n];
    for (int i = 0; i < n; i++) {
        printf("vetor[%d]: ", i);
        scanf("%f", &vetor[i]);
        soma += (vetor[i] / pow(i + 1, 2));
    }
    s = cbrt(soma);
    printf("O valor de \"S\" eh %f", s);
}
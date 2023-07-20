#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//Davi Tiago Soares. Numero de matricula: 12211BSI240, Matheus Soares Costa. Numero de matricula: 12211BSI215
int main() {
    int n;
    float soma, media, somatorio, d;
    printf("Quantos valores deseja ler? ");
    scanf("%d", &n);
    float vetor[n];
    for (int i = 0; i < n; i++) {
        printf("vetor[%d]: ", i);
        scanf("%f", &vetor[i]);
        soma += vetor[i];
    }
    media = soma / n;
    for (int i = 0; i < n; i++) {
        somatorio += pow((vetor[i] - media), 2);
    }
    d = sqrt(somatorio / (n - 1));
    printf("O valor de \"d\" eh %f", d);
}
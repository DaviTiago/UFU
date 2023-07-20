#include<stdlib.h>
#include<stdio.h>
#include <math.h>
#include<string.h>
//Nome: Davi Tiago Soares. Nº 12211BSI240
int main() {
int M, N, P;
for(int i=0; i<1; i++){
 printf("Digite o numero de linhas e colunas da matriz A\n");
 scanf ("%d%d",&M,&N);
  if (M<1 || N<1){
    printf(" Numeros de L: %d ou C: %d invalidos digite outros\n",M,N);
    i--;
 } }
for(int i=0; i<1; i++){
 printf("Digite o numero de colunas da matriz B\n");
 scanf ("%d",&P);
  if (P<1){
    printf(" Numero de C: %d invalido digite outro\n",P);
    i--;
 } }

int **matA, **matB, **matR, i, j, k, n = N, m = M;

matA = malloc(M * sizeof(int *));

for(i=0; i<M; i++){
    matA[i]= calloc(N , sizeof(int));
    
}

for(i=0; i<M; i++){
    for(j=0; j<N; j++){
        printf("Digite o valor de matA[%d][%d]:", i,j);
        scanf("%d",&matA[i][j]);

    }
}
printf("MatA\n");
for(i=0; i<M; i++){
    for(j=0; j<N; j++){
        printf("%3d",matA[i][j]);



    } printf("\n");
}

matB = malloc(n * sizeof(int *));
for(int i=0; i<n; i++){
    matB[i] = calloc(P , sizeof(int));
}

for(int i=0; i<n; i++){
    for(int j=0; j<P; j++){
        printf("Digite o valor de matB[%d][%d]:", i,j);
        scanf("%d",&matB[i][j]);

    }
}
 printf("MatB:\n");
for(i=0; i<N; i++){
    for(j=0; j<P; j++){
        printf("%3d",matB[i][j]);
    }
    printf("\n");
    }

    matR = malloc(M *sizeof(int *));
    for(int i=0; i<M; i++){
        matR[i]=calloc(P , sizeof(int));
    }
    for(int i=0; i<M; i++){
    for(int j=0; j<P; j++){
        matR[i][j]=0;
        for(int k=0; k<N; k++){
            matR[i][j]+=matA[i][k] * matB[k][j];
        }
    }
}
 printf("MatR:\n");
for(i=0; i<M; i++){
    for(j=0; j<P; j++){
        printf("%3d ",matR[i][j]);
    }
    printf("\n");
    }
for(i=0; i<M; i++){
    free(matA[i]);
    }
free(matA);

for(i=0; i<n; i++){
    free(matB[i]);
    }
free(matB);

for(i=0; i<M; i++){
    free(matR[i]);
    }
free(matR);

return 0;
}
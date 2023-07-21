#include<stdio.h>
#include<stdlib.h>
#include<math.h>
/*2. Escreva um programa que leia duas matrizes de inteiros. Cada matriz deve ter, no
máximo, cinco linhas e cinco colunas. Em seguida, implemente uma função que
calcule a multiplicação dessas duas matrizes, imprimindo o resultado. A função
deve verificar se é possível calcular a multiplicação. Teste seu programa com várias
matrizes diferentes.*/
int **multiplica (int **matA, int **matB, int linhaA, int linhaB, int ColunaA, int ColunaB){
    if (ColunaA != linhaB){
        printf("Não eh possiver fazer a multiplicacao, o numero de colunas da matriz A deve ser o mesmo numero de linhas da matrizB\n");
        return 0;
    }
    int **matC = calloc (linhaA, sizeof(int*));
        for (int i = 0; i < linhaA; i++){
        matC[i] = calloc(ColunaB, sizeof(int));
    }
    if(matC ==NULL){
        printf("Erro: não foi possível alocar memória para a matriz C\n");
        return 0;
    }
    
      for(int i=0; i<linhaA; i++){
        for(int j=0; j<ColunaB; j++){
            for (int k = 0; k < ColunaA; k++) {
             matC[i][j] += matA[i][k] *matB[k][j];
        
            }

        }
    }
        printf("\nMatriz resultante:\n");
    for (int i = 0; i < linhaA; i++) {
        for (int j = 0; j < ColunaB; j++) {
            printf("[%d] ", matC[i][j]);
        }
        printf("\n");
    }

return matC;


}

int main(){
    int linhaA, ColunaA, linhaB, ColunaB;
    do{
    printf("Digite o número de linhas e colunas da matriz A: max(5x5)\n");
    scanf("%d%d",&linhaA,&ColunaA);
    printf("Digite o número de linhas e colunas da matriz B:max(5x5)\n");
    scanf("%d%d",&linhaB,&ColunaB);

    }while(linhaA >5 || ColunaA > 5 || linhaB > 5 || ColunaB >5 );

   

    int **matA =malloc(linhaA *sizeof(int*));
    for(int i=0; i<linhaA; i++){
        matA[i] = calloc (ColunaA, sizeof(int));
    }
   
    if (matA == NULL) {
        printf("Erro: não foi possível alocar memória para a matriz A\n");
        return 1;
    }
    // leitura matA
    for(int i=0; i<linhaA; i++){
        for(int j=0; j<ColunaA; j++){
            printf("Digite os valores da matA [%d][%d]",i,j);
            scanf("%d",&matA[i][j]);
        }
    }
    
    int **matB = calloc(linhaB, sizeof(int*));
    for(int i=0; i<linhaB; i++){
        matB[i]= calloc (ColunaB, sizeof(int));
    }
    if (matB == NULL) {
        printf("Erro: não foi possível alocar memória para a matriz A\n");
        return 1;
    }
    printf("\n\n");
    //leitura matB
     for(int i=0; i<linhaB; i++){
        for(int j=0; j<ColunaB; j++){
            printf("Digite os valores da matB [%d][%d]",i,j);
            scanf("%d",&matB[i][j]);
        }
    }   
    
    int **matC = multiplica(matA, matB, linhaA, linhaB, ColunaA, ColunaB);

    for(int i=0; i<linhaA; i++){
    free(matA[i]);}
    free(matA);
    
    for(int i=0; i<linhaB; i++){
    free(matB[i]);}
    free(matB);
    
    if(matC != NULL){
    for(int i=0; i<linhaA; i++){
    free(matC[i]);}
    free(matC);}

    return 0;
}
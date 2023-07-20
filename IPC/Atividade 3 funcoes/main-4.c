#include<stdio.h>
#include<stdlib.h>

//Nome: Davi Tiago Soares. Nª: 12211BSI240

float **aloca(int linha, int coluna){
    float** matriz = malloc(linha * sizeof(float *));

    for(int i =0; i< linha; i++){
        matriz[i]= calloc(coluna, sizeof(float));
    }
    return matriz;
}
void leitura(float** matriz, int linha, int coluna){
    for(int i=0; i<linha; i++){
        for(int j=0; j< coluna; j++){
            printf("Digite os numeros[%d][%d]",i,j);
            scanf("%f",&matriz[i][j]);
        }
    }
    printf("\n");
    return;
}
float** multiplica(float** matrizA, int linhaA, int colunaA, float** matrizB, int linhaB, int colunaB){

    float** matrizC = aloca(linhaA, colunaB);
    for(int i=0; i<linhaA; i++){
        for(int j=0; j<colunaB; j++){
          matrizC[i][j] = 0;
          for (int k = 0; k < colunaA; k++) {
             matrizC[i][j] += matrizA[i][k] *matrizB[k][j];
        
            }

        }
    }
return matrizC;
}

void imprime(float** matriz, int linha, int coluna){
        for(int i=0; i<linha; i++){
          for(int j=0; j< coluna; j++){
              printf("Matriz[%d][%d] : %f\n",i,j,matriz[i][j]);
            }
        }
    printf("\n");
    return;
}

void desaloca(float** matriz,int coluna){
    for(int i=0; i<coluna; i++){
        free(matriz[i]);

    }
    return;
}

int main (){
 float **m1 = aloca(2,3);
 leitura(m1,2,3);

 float **m2 = aloca(3,4);
 leitura(m2,3,4);

 float **m3 = multiplica (m1,2,3,m2,3,4);
printf("MatrizA\n");
 imprime(m1,2,3);
 printf("MatrizB\n");
 imprime(m2,3,4);
 printf("MatrizC\n");
 imprime(m3,2,4);

 desaloca(m1,2);
 desaloca(m2,3);
 desaloca(m3,2);

 return 0;
}


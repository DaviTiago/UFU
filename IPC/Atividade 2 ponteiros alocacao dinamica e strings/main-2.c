#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//Nome: Davi Tiago Soares. Nº 12211BSI240
//ex2
int main(){
 float ***cubo,soma; 
 int i, j, k,l,c,p, escolha=0, x=0, y=0, z=0;

 for(int i=0; i<1; i++){
 printf("Digite o numero de linhas e colunas e profundidade da matriz\n");
 scanf ("%d%d%d",&l,&c,&p);
  if (l<1 || c<1 || p<1){
    printf(" Numeros de L: %d ou C: %d ou P: %d invalidos digite numeros > 0\n",l,c,p);
    i--;}}

    cubo = malloc(l * sizeof(float**));
    for(int i=0; i<l; i++){
        cubo[i]= calloc(c , sizeof(float*));
    }

    for(i=0; i<l; i++){
        for(j=0; j<c; j++){
            cubo[i][j] = calloc(p, sizeof(float));
        }
    }
    for(i=0; i<l;i++){
        for(j=0;j<c;j++){
            for(k=0; k<p;k++){
            printf("Digite os numeros que serao inseridos[%d][%d][%d]\n",i,j,k);
            scanf(" %f",&cubo[i][j][k]);
               }}}
    


    for(i=0; i<l;i++){
        for(j=0;j<c;j++){
            for(k=0; k<p;k++)
            printf("%3f ",cubo[i][j][k]);
            
        }
        printf("\n");
    }
    do{
            printf("Escolha o par ordenado 1-XY 2-XZ 3-YZ\n");
            scanf("%d",&escolha);
            
        }while (escolha<=0 || escolha>=4);
    if(escolha==1){
        do{
        
            printf("Digite o ponto de X\n");
            scanf("%d",&x);
            printf("Digite o ponto de Y\n");
            scanf("%d",&y);
        }while((x<=0||x>l) || (y<=0||y>c));
    
        x--;
        y--;
               
        for(z=0; z<p; z++){
            soma = soma+cubo[x][y][z];
            
        }
        printf("A soma dos numeros:");
        for(z=0; z < p; z++){
            
                printf(" %f ",cubo[x][y][z]);  
            
        }
    }
    else if(escolha==2){
        do{
            printf("Digite o ponto de X\n");
            scanf("%d",&x);
            printf("Digite o ponto de Z\n");
            scanf("%d",&z);
        }while((x<=0|| x>l) || (z<=0 || z>p));

        x--;
        z--;

        for(y=0; y < c; y++){
            soma = soma+cubo[x][y][z];
        }
        printf("A soma dos numeros:");
        
        for(y=0; y < c; y++){
            
                printf("%f, ",cubo[x][y][z]);
        }
    }
    else{
        do{
            printf("Digite o ponto de Y\n");
            scanf("%d",&y);
            printf("Digite o ponto de Z\n");
            scanf("%d",&z);
        }while((y<=0||y>c)||((z<=0||z>p)));
        y--;
        z--;

        for(x=0; x<l; x++){
            soma = soma + cubo[x][y][z];
        }
        printf("A soma dos numeros:");
        for(x=0; x<l; x++){
            printf("%f, ", cubo[x][y][z]);
        }
    }

    printf("= %f",soma);

    for (i = 0; i < l; i++) {
        for (j = 0; j < c; j++) {
            free(cubo[i][j]);
        }
        free(cubo[i]);
    }
    free(cubo);

    return 0;
}
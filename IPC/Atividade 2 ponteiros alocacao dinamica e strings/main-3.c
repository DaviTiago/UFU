#include<stdlib.h>
#include<stdio.h>
#include<string.h>

//Nome: Davi Tiago Soares Nº:12211BSI240.

int main() {
    char n[5][20],aux[20];
    int i,j,c;
    printf("Digite os nomes:\n");
    for(int i=0; i<5; i++){
        gets(n[i]);
    }
    strcpy(aux,n[0]);
    
        for(int i=0; i<5; i++){
            if((strcmp(n[i],aux)<0)){
                for(int j=0; j<20; j++){
                    aux[j]=n[i][j];
                }

            }

        }

printf("O primeiro nome da lista eh: %s",aux);
return 0;
}


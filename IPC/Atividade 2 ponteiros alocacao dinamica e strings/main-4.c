#include <string.h>
#include <stdlib.h>
#include <stdio.h>

//Nome: Davi Tiago Soares. Nº: 12211BSI240.

int main (){
char M[100] = "The quick brown fox jumps over the lazy dog";
char N[100] = "A ligeira raposa marrom saltou sobre o cachorro preguicoso";
char R[100];
int i,j,k=0,cont=0;
// 1) imprimir o tamanho das strings M e N

     while(M[i]!='\0')
    {
        i++;
        cont++;
    }
printf("O tamanho da String M: %d\n",i);

for(k=0; k<100; k++){
    if(N[k]=='\0'){

    break;
}}
printf("O tamanho da String N: %d\n",k);

// 2) copiar M para R
for(int i=0; i<100;i++){
R[i]=M[i];
if(M[i]=='\0'){
    break;
}}
printf("%s\n",R);

//3) concatenar N em R

for(int j=0; j<100; j++)
{
    R[i+j]=N[j];
    if(N[j]=='\0'){
        break;
    }
}

printf("%s",R);

return 0;
}


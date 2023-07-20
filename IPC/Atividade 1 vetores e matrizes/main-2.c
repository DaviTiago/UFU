#include<stdlib.h>
#include<stdio.h>
// Davi Tiago Soares. Numero de matricula: 12211BSI240, Matheus Soares Costa. Numero de matricula: 12211BSI215

int main (){

 int i,j, vet[10];

 printf("Digite 10 numeros\n");
 for(i =0; i<10; i++){
  scanf("%d",&vet[i]);

 for(j=0; j<i; j++){
if(vet[i]==vet[j]){
    printf("numero repetido, digite outro\n");
    i--;} } }

for( i =0; i<10; i++){
printf("%d, ",vet[i]);}
 return 0;
}

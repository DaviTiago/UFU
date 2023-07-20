#include <stdio.h>
#include <stdlib.h>
// Davi Tiago Soares. Numero de matricula: 12211BSI240, Matheus Soares Costa. Numero de matricula: 12211BSI215

int main()
{
float  vet[20],aux;
     printf("Digite 20 numeros\n");
     for(int i =0; i<20; i++)
    scanf("%f", &vet[i]);
    for(int i=0; i<20; i++){
            for(int j=i; j<20; j++)
            if(vet[i]>vet[j]){
                aux=vet[i];vet[i]=vet[j];vet[j]=aux;
}
printf("%f, ",vet[i]);
}
return 0;
}

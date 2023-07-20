#include<stdlib.h>
#include<stdio.h>
#include<math.h>

//Nome: Davi Tiago Soares. Nª: 12211BSI240

float imc(float peso,float altura){ 
    return (peso/pow(altura,2));
}
float peso, altura;
int main(){
printf("Digite o peso\n");
scanf("%f",&peso);
printf("Digite a altura\n");
scanf("%f",&altura);
printf("Seu IMC eh:%f",imc(peso,altura));


    return 0;
}
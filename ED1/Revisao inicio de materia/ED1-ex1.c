#include<stdio.h>
#include<stdlib.h>
#include<math.h>
/*1. Escreva um programa que leia um vetor (fornecido pelo usuário) de tamanho 10. O
vetor deve conter apenas números inteiros e não precisa estar ordenado. Em seguida,
implemente as seguintes funções, sem ordenar previamente o vetor.
(a) Mostrar os valores do vetor;
(b) Encontrar o maior valor deste vetor;
(c) Encontrar os dois maiores valores do vetor, percorrendo o vetor apenas uma
vez;
(d) Calcular a média dos valores do vetor;
(e) Verificar se existem dois valores iguais no vetor;
(f) Mostrar os valores do vetor em ordem inversa;
(g) Contar o número de elementos ímpares no vetor.
Cada item anterior deve ser implementado em uma função. Na main, você deve
apenas ler os dados do vetor, chamar as funções e imprimir os resultados, quando
possível.*/

//(a) Mostrar os valores do vetor;
void apresentar(int *vetor, int tamanho){
        for(int i=0; i<tamanho; i++){
        printf("[%d] ",vetor[i]);}
        printf("\n");
        
}
//(b) Encontrar o maior valor deste vetor;
int maiorvalor(int *vet,int tamanho){
    int maiorvalor = vet[0];
    for(int i=1; i< tamanho; i++){
        if(maiorvalor < vet[i]){
            maiorvalor=vet[i];
        }
    }
    return maiorvalor;

}
//(c) Encontrar os dois maiores valores do vetor, percorrendo o vetor apenas uma vez;
int segundomaior(int *vet, int tamanho,int *maior) {
    int segundo= INT_MIN, aux;
    aux=*maior = vet[0];
    for (int i = 0; i < tamanho; i++) {
        if (vet[i] > *maior) {
            aux = *maior;
            *maior = vet[i];
            segundo = aux;
        } else if (vet[i] < *maior && vet[i] > segundo) {
            segundo = vet[i];
        }
    }
    return segundo;
}

//(d) Calcular a média dos valores do vetor;
float media (int *vet, int tamanho){
    float soma, media;
    for (int i=0; i< tamanho; i++){
        soma= soma + vet[i];
    }
    media= soma/ tamanho;
    return media;
}
//(e) Verificar se existem dois valores iguais no vetor;
int iguais(int *vet, int tamanho){
    for (int i=0; i< tamanho; i++){
        for(int j=i+1; j<tamanho; j++){
            if(vet[i]==vet[j]){
                
                return 1;

            }    
        }
    }return 0;

}

//(f) Mostrar os valores do vetor em ordem inversa;
void inversa (int *vet, int tamanho){
    for(int i=tamanho-1; i>=0; i--){
        printf("[%d] ", vet[i]);
    }
    printf("\n");
}
//(g) Contar o número de elementos ímpares no vetor.
int impar (int *vet, int tamanho){
    int impar=0;
    for(int i=0; i< tamanho; i++){
        if((vet[i] % 2)>0 ){
        impar ++;}
    }
    return impar;
}


int main(){
    int tamanho =10, maior, maior2;
    
    int  *vet = calloc (10, sizeof(int));
    for(int i=0; i<10; i++){
        printf("Digite os valores do vetror [%d]:",i);
        scanf("%d",&vet[i]);
    }

    apresentar(vet, tamanho);
    maior= maiorvalor(vet, tamanho);
    printf("O maior valor eh: %d\n", maior);
    
    maior2= segundomaior(vet, tamanho,& maior);
    printf("O segundo maior valor eh: %d\n", maior2);

    printf("A meida dos valores eh: %.2f\n",media(vet, tamanho));

    if(iguais(vet, tamanho)){
        printf("Existem valores iguais\n");
    }
    else{
        printf("Nao existem valores iguais\n");
    }

    inversa(vet, tamanho);

    printf("O vetor tem %d numeros impares ", impar(vet,tamanho));

    free(vet);


    return 0;
}
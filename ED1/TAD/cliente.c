#include <stdlib.h> // para funcao exit()
#include <stdio.h>
#include "vetor.h"
// (a) somar o elementos de um vetor;
float somar(Vetor *v){
    float soma=0;

    for (int i = 0; i < v->tamanho; i++){
		soma = soma + v->dados[i];
	}
	return soma;
}
//(b) calcular a media aritmetica dos valores de um vetor;
float media(Vetor *v){
    float media;
    float soma = somar(v);

    media = soma/v->tamanho;

    return media;
    }
//(c) encontrar o maior elemento de um vetor (lembrando que o vetor nao esta, necessariamente, ordenado).

float maior (Vetor *v){
    float maior = v->dados[0];
    for (int i=0; i< v->tamanho; i++){
            if(maior < v->dados[i]){
                maior = v->dados[i];
            }
    }
    return maior;
}

int main()
{
  Vetor *V;
  int tam;
  float valor;


  printf("Forneca o tamanho do vetor: ");
  scanf("%d", &tam);

  V = criar(tam);
  if (V == NULL) {
    printf("Erro: nao foi possivel criar o vetor\n");
    exit(1);
  }

  for (int i = 0; i < tamanho(V); i++) {
    printf("Digite o %do. valor: ", i+1);
    scanf("%f", &valor);
    inserir(valor, V, i);
  }

  printf("Se deseja remover elemento digite 1 se nao digite outro numero\n");
  int teste, posicao;
  scanf("%d",&teste);
  if(teste == 1){
        printf("Qual a posicao do elemento que deseja remover\n");
        scanf("%d",&posicao);
        float removido = remover(V, posicao);
        printf("Valor removido: %f\n", removido);
        }
        else{
      printf("Ok sem remover\n");

  }

  for (int i = 0; i < tamanho(V); i++) {
    acessar(V, i, &valor);
    printf("%f ", valor);
  }
  printf("\nO valor da soma eh: %f\n", somar(V));
  printf("A media dos valores eh: %f\n", media(V));
  printf("O maior numero do vetor eh: %f\n", maior(V));


  destruir(V);
  return 0;
}

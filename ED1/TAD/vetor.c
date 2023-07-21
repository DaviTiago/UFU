#include "vetor.h"
#include <stdlib.h>

/*
  Entrada: valor inteiro que representa o tamanho do vetor
  Saida: ponteiro para o vetor, ou NULL caso nao seja possivel cria-lo
  Pre-condicao: o tamanho deve ser menor ou igual ao tamanho maximo do vetor (ou seja, 10)
  Pos-condicao: nao existe
*/
Vetor *criar(int tam)
{
  Vetor *vet;

  vet = malloc(sizeof(Vetor));
  vet->tamanho = tam;

  return vet;
}

/*
  Entrada: ponteiro para um vetor
  Saida: nao existe
  Pre-condicao: nao existe
  Pos-condicao: memoria do vetor eh desalocada
*/
void destruir(Vetor *vet)
{
  if (vet != NULL) free(vet);
}

/*
  Entrada: um valor em ponto flutuante, um ponteiro para vetor e a posicao onde o valor sera inserido
  Saida: 1, se a posicao for valida, 0 caso contrario
  Pre-condicao: o ponteiro tem que ser valido
  Pos-condicao: o valor na posicao eh modificado
*/
int inserir(float valor, Vetor *vet, int pos)
{
  if (pos < 0 || pos >= vet->tamanho)
    return 0;

  vet->dados[pos] = valor;
  return 1;
}

/*
  Entrada: um ponteiro para vetor, uma posicao e um valor em ponto flutuante passado por referencia
  Saida: 1, se a posicao for valida, 0 caso contrario
  Pre-condicao: o ponteiro tem que ser valido
  Pos-condicao: a variavel valor eh modificada
*/
int acessar(Vetor *vet, int pos, float *valor)
{
  if (pos < 0 || pos >= vet->tamanho)
    return 0;

  *valor = vet->dados[pos];
  return 1;
}

/*
  Entrada: um ponteiro para vetor
  Saida: tamanho do vetor
  Pre-condicao: ponteiro tem que ser valido
  Pos-condicao: nao existe
*/
int tamanho(Vetor *vet) {
  return vet->tamanho;
}

//remover um elemento de vetor
/*
 Entrada: Um ponteiro para vetor, uma posicao
 Saida: Valor removido
 Pre-condicao: O ponteiro tem que ser valido
 Pos-condicao: O vetor deve ser modificado retirando o valor na posi��o escolhida, o tamanho � decrementado em 1
*/
float remover(Vetor *vet, int pos){

    if(pos >= vet->tamanho || pos < 0){
        return 0;
    }
    float removido= vet->dados[pos];

    for(int i= pos; i<vet->tamanho-1; i++){
        vet->dados[i] = vet->dados[i+1];
    }
    vet->tamanho--;

    return removido;

}

#include <stdio.h>
#include<stdlib.h>

#define MAX 5 //TAMANHO

// Definir a ED pilha
struct pilha {
	int topo;
	char elementos[MAX];
};

// Definir o tipo de dados Pilha
typedef struct pilha Pilha;

/*
  Entrada: nao existe
  Saida: ponteiro para Pilha, ou NULL caso nao seja possivel cria-la
  Pre-condicao: nao existe
  Pos-condicao: nao existe
*/
Pilha *pilha_criar()
{
	
	Pilha *p;

	p = malloc(sizeof(Pilha));
	if (p != NULL);
		p->topo = -1;

	return p;
}

/* 
 * Entrada: uma pilha
 * Saida: nao existe
 * Pre-condicao: nao existe
 * Pos-condicao: memoria da pilha liberada
 */
void pilha_destruir(Pilha *p)
{
	if (p != NULL) free(p);
}

/*
 * Entrada: uma pilha
 * Saida: 1 se a pilha for vazia, 0 caso contrario
 * Pre-condicao: pilha deve ser valida
 * Pos-condicao: nao existe
 */
int pilha_vazia(Pilha *p)
{
	if (p->topo == -1) return 1; // true
	else return 0; // false
}

/*
 * Entrada: uma pilha
 * Saida: 1 se a pilha for cheia, 0 caso contrario
 * Pre-condicao: pilha deve ser valida
 * Pos-condicao: nao existe
 */
int pilha_cheia(Pilha *p)
{
	if (p->topo == (MAX-1))
		return 1; // true
	else return 0; // false
}

/*
 * Entrada: uma pilha e um caractere
 * Saida: 1 se bem sucedida, 0 caso contrario
 * Pre-condicao: pilha tem que ser valida e caractere tambem
 * Pos-condicao: conteudo da pilha alterado
 */
int empilhar(Pilha *p, char x)
{
	if (pilha_cheia(p) == 1)
		return 0;	// false
	else {
		p->topo = p->topo + 1;
		p->elementos[ p->topo ] = x;
		
		return 1;	// true
	}
}

/*
 * Entrada: uma pilha e um caractere passado por referencia
 * Saida: 1 se bem sucedida, 0 caso contrario
 * Pre-condicao: pilha tem que ser valida
 * Pos-condicao: conteudo da pilha alterado
 */
int desempilhar(Pilha *p, char *x)
{
	if (pilha_vazia(p) == 1)
		return 0;	// false
	else {
		*x = p->elementos[ p->topo ];
		p->topo = p->topo - 1;
		
		return 1;	// true
	}
}

// Definir a ED fila
struct fila {
	int primeiro;
	int final;
	int nro_elementos;
	char elementos[MAX];
};

// Definir o tipo de dados Fila
typedef struct fila Fila;

/*
  Entrada: nao existe
  Saida: ponteiro para Fila, ou NULL caso nao seja possivel cria-la
  Pre-condicao: nao existe
  Pos-condicao: nao existe
*/
Fila *fila_criar()
{
	
	Fila *f;

	f = malloc(sizeof(Fila));
	if (f != NULL) {
		f->primeiro = 0;
		f->final = 0;
		f->nro_elementos = 0;
	}

	return f;
}

/* 
 * Entrada: uma fila
 * Saida: nao existe
 * Pre-condicao: nao existe
 * Pos-condicao: memoria da fila liberada
 */
void fila_destruir(Fila *f)
{
	if (f != NULL) free(f);
}

/*
 * Entrada: uma fila
 * Saida: 1 se a fila for vazia, 0 caso contrario
 * Pre-condicao: fila deve ser valida
 * Pos-condicao: nao existe
 */
int fila_vazia(Fila *f)
{
	if (f->nro_elementos == 0) return 1; // true
	else return 0; // false
}

/*
 * Entrada: uma fila
 * Saida: 1 se a fila for cheia, 0 caso contrario
 * Pre-condicao: fila deve ser valida
 * Pos-condicao: nao existe
 */
int fila_cheia(Fila *f)
{
	if (f->nro_elementos == MAX) return 1; // true
	else return 0; // false
}

/*
 * Entrada: uma fila e um caractere
 * Saida: 1 se bem sucedida, 0 caso contrario
 * Pre-condicao: fila tem que ser valida e caractere tambem
 * Pos-condicao: conteudo da pilha alterado
 */
int inserir(Fila *f, char x)
{
    //if (cheia(f))
	if (fila_cheia(f) == 1)
		return 0;	// false
	else {
		f->nro_elementos = f->nro_elementos + 1;
		f->elementos[ f->final ] = x;
		
		// avanca o indice Final. Atencao: o vetor eh circular
		if (f->final == (MAX-1))
		    f->final = 0;
		else
		    f->final = f->final + 1;
		
		return 1;	// true
	}
}

/*
 * Entrada: uma fila e um caractere passado por referencia
 * Saida: 1 se bem sucedida, 0 caso contrario
 * Pre-condicao: fila tem que ser valida
 * Pos-condicao: conteudo da fila alterado
 */
int retirar(Fila *f, char *x)
{
	if (fila_vazia(f) == 1)
		return 0;	// false
	else {
	    f->nro_elementos = f->nro_elementos - 1;
	    *x = f->elementos[ f->primeiro ];
	    
	    if (f->primeiro == (MAX-1))
	        f->primeiro = 0;
	    else f->primeiro = f->primeiro + 1;
		
		return 1;	// true
	}
}

/*Considere uma Pilha P vazia e uma Fila F não vazia. Utilizando apenas os testes de
Fila e Pilha vazias, as operações Inserir, Retirar, Empilhar e Desempilhar, e uma
variável aux do tipo char, escreva uma função que inverta a ordem dos elementos
da Fila.*/
/*
Entrada: uma fila, uma pilha um carcter aux
Saida:1 se bem sucedido, 0 caso contrário
pré-requisito: Pilha vazia, fila não vazia
pós-requisito:A fila deve estar invertida
*/
int inverte(Fila *F, Pilha *P){
	char c;

	if(fila_vazia(F)==1)return 0; //False fila vazia
	else{
		while(fila_vazia(F)==0){
			retirar(F,&c);
			if(pilha_cheia(P)==1)
			return 0;
			empilhar(P,c);
			
		}
		while(!pilha_vazia(P)){
			desempilhar(P,&c);
			if(inserir(F,c)==0)
			return 0;

		}
		return 1; //True, todos os elementos foram invertidos
	}
}

int main()
{
	Pilha *P;
	char c, aux;
	Fila *F;

	int teste,teste2;

	P = pilha_criar();
	F= fila_criar();
	if (P == NULL) {
		printf("Erro: nao foi possivel criar a pilha\n");
		exit(-1);
	}

	/*for (int i = 0; i < 8; i++) {
		printf("Digite um caractere: ");
		scanf(" %c", &c);

		teste = empilhar(P, c);
		printf("Teste = %d\n", teste);
	}*/

	while (fila_cheia(F) == 0) {
		printf("Digite um caractere: ");
		scanf(" %c", &c);
		inserir(F, c);
	}
	teste2=inverte(F,P);

	while (retirar(F, &c) == 1)
		printf("%c\n", c);

	pilha_destruir(P);
	fila_destruir(F);
    

	return 0;
}
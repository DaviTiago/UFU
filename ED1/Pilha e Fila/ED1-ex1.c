//ex1
#include <stdio.h>
#include<stdlib.h>

#define MAX 5 //TAMANHO

typedef struct fila{
    int primeiro;
    int final;
    int nro_elementos;
    char elementos[MAX];
}Fila;
/*
Entrada: não existe
Saida: Ponteiro para fila, ou NULL caso não possa cria-la
Pré-condição: não existe
Pós- condição: não existe
*/
Fila *criar (){
    Fila *fila;
    fila = malloc(sizeof(Fila));
    if(fila!=NULL){
        fila->primeiro=0;
        fila->final =0;
        fila->nro_elementos = 0;
    }
    return fila;
}
/*
Entrada: Ponteiro para a fila
Saida: Não existe
Pré-condição: não existe
Pós- condição: memoria da fila liberada
*/

void destruir (Fila *fila){
    if (fila!= NULL) free(fila);
}

/*
Entrada: Uma Fila 
Saida: 1 se a fila for vazia, 0 caso contrário
Pré-condição: Fila valida
Pós-condição: Não existe
*/
int vazia(Fila *fila){
    if(fila ->nro_elementos == 0) return 1; // 1 = True
    else return 0; // 0 = False
}


/*
Entrada: Uma Fila 
Saida: 1 se a fila for cheia, 0 caso contrário
Pré-condição: Fila valida
Pós-condição: Não existe
*/
int cheia(Fila *fila){
    if(fila->nro_elementos == MAX ) return 1; // 1 = True
    else return 0; // 0 = False
}

/*
Entrada: Uma fila, um caractere
Saida: 1 se der certo, 0 caso contrário
Pré-condição: entrada válida
Pós-condiçao: fila alterada
*/
int inserir ( Fila *fila, char x){
    if(cheia(fila)==1)
    return 0; //false
    else{
        fila->nro_elementos = fila->nro_elementos+1;
        fila->elementos[fila->final]=x;
        //avança o indice final. Obs: O vetor é circular
        if(fila->final == (MAX-1))
        fila->final = 0;
        else fila->final = fila->final +1;
        return 1; // True
    }
}
//Caso não fosse circular
/*
int inserir(Fila *fila, char x)
{
    if (cheia(fila) == 1)
        return 0; // false
    else {
        fila->nro_elementos = fila->nro_elementos + 1;
        fila->elementos[fila->final] = x;
        fila->final = fila->final + 1;
        return 1; // true
    }
}*/
/*
Entrada: Uma fila e um caractere passado por referencia
Saida: 1 se bem sucedida, 0 caso contrario
Pré-condição: fila tem que ser valida
Pós-condição: conteudo da fila alterado
*/
int retirar(Fila *fila, char *x)
{
	if (vazia(fila) == 1)
		return 0;	// false
	else {
	    fila->nro_elementos = fila->nro_elementos - 1;
	    *x = fila->elementos[ fila->primeiro ];
	    // avanca o indice Primeiro. obs: o vetor eh circular
	    if (fila->primeiro == (MAX-1))
	        fila->primeiro = 0;
	    else fila->primeiro = fila->primeiro + 1;
		
		return 1;	// true
	}
}
/*
Entrada: Uma fila, um caractere
Saida: 1 se bem sucedida, 0 caso contrário
Pré-condição: A fila não pode estar cheia
Pós-condição: ALteração na fila
*/
int fura_fila(Fila *fila, char x){
    if(cheia(fila)==1)
    return 0; // False
    else {
        fila->nro_elementos = fila->nro_elementos+1;
        if(fila->primeiro == 0){
            fila->primeiro = MAX-1;
        }
        else
            fila->primeiro = fila->primeiro -1;  
        fila->elementos[fila->primeiro] = x;
        return 1;
    }
}
int main()
{
	Fila *fila;
	char c,t;

	int teste, teste2;

	fila = criar();
	if (fila == NULL) {
		printf("Erro: nao foi possivel criar a fila\n");
		exit(-1);
	}

	for (int i = 0; i < 5; i++) {
		printf("Digite um caractere:");
		scanf(" %c", &c);
         teste = inserir(fila, c);
    // Furando a fila
        if(i>=3){
            printf("Se deseja furar a fila: [s] ou [n]\n");
            scanf(" %c", &t);
            if(t == 's' || t == 'S'){
                printf("Digite um caractere para furar a fila: ");
                scanf(" %c", &c);
                teste2 = fura_fila(fila,c);  
                i++;              

                if (teste2 == 0) {
                    printf("Erro: nao foi possivel furar a fila\n");
                }
            }
        }
    }
                    
		//printf("Teste = %d\n", teste);

     //while (!cheia(F)) {
	/*while (cheia(F) == 0) {
		printf("Digite um caractere: ");
		scanf(" %c", &c);
		inserir(F, c);
	}*/

	while (retirar(fila, &c) == 1)
		printf("%c\n", c);

	destruir(fila);

	return 0;
}
#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

//declaraçao do no (Node) da lista encadeada simples
struct node{
    char info;
    struct node *next;
};
typedef struct node Node;

//declaraçao da pilha
typedef struct pilha{
    Node *topo;
}Pilha;

Node *newNode(){
    Node *n;
    n=malloc(sizeof(Node));

    return n;
}
void deleteNode(Node *n){
    if (n!= NULL) free(n);

}
Pilha *criar(){
    Pilha *P;
    P= malloc(sizeof(Pilha));
    if(P != NULL) P-> topo = NULL; //Pilha vazia topo aponta para NULL
    
    return P;
}

int cheia(Pilha *P){
    return 0;// por estar alocada dinamicamente nunca estará cheia
}

int vazia(Pilha *P){

    if (P->topo == NULL) return 1; // pilha vazia
    
}
//insere um elemento na pilha
//retorna 1 se deu certo 0 caso contrario
int empilhar(Pilha *P, char x){
    Node *Paux;

    if(cheia(P)==1){
        return 0;
    }
    Paux = newNode();
    if (Paux == NULL){
        return 0;}

    Paux->info = x;
    Paux -> next = P->topo;
    P->topo=Paux;

    return 1;

}
int desempilha(Pilha *P, char *x){
    Node *Paux;
    if (vazia(P)==1) return 0;
    Paux=P->topo;
    *x=Paux->info;
    P->topo=Paux->next;
    deleteNode(Paux); 
    return 1;
}


void destruir(Pilha *P)
{
    char valor;
    // enquanto a pilha nao for vazia,
    // remova (delete) todos os nodes
    while(vazia(P) == 0) {
    	desempilha(P, &valor);
    }
    
    free(P);
}

int main()
{
    Pilha *P;
    char valor;
    
    // Criar a pilha
    P = criar();
    if (P == NULL) {
        printf("Erro ao criar a pilha\n");
        exit(1);
    }
    empilhar(P, 'A');
    empilhar(P, 'B');
    empilhar(P, 'C');
    empilhar(P, 'D');
    empilhar(P, 'E');
    
    // alternativa: while(!vazia(P)) {
    while(vazia(P) != 1) {
    	desempilha(P, &valor);
    	printf("%c ", valor);
    }
    printf("\n");
    
    destruir(P);
    
    return 0;
}
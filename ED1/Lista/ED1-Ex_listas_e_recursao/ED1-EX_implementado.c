#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// Declaração do nó (node) da lista encadeada simples
struct node {
    int info;
    struct node *next;
};

// Definição do tipo Node
typedef struct node Node;

// Declaração da lista em si
struct lista {
    Node *head;
};

// Definição do tipo Lista
typedef struct lista Lista;

// Função: newNode
// Entrada: N/A
// Saída: Ponteiro para um novo nó alocado dinamicamente
// Pré-requisito: N/A
// Pós-requisito: Aloca dinamicamente memória para um novo nó e retorna um ponteiro para esse nó
Node *newNode()
{
    Node *n;

    // Se não puder alocar, retorna NULL
    n = malloc(sizeof(Node));

    return n;
}

// Função: deleteNode
// Entrada: Ponteiro para um nó
// Saída: N/A
// Pré-requisito: N/A
// Pós-requisito: Libera a memória alocada para o nó
void deleteNode(Node *n)
{
    if (n != NULL) free(n);
}

// Função: criar
// Entrada: N/A
// Saída: Ponteiro para uma nova lista alocada dinamicamente
// Pré-requisito: N/A
// Pós-requisito: Aloca dinamicamente memória para uma nova lista, define o ponteiro head como NULL e retorna um ponteiro para a lista
Lista *criar()
{
    Lista *L;

    L = malloc(sizeof(Lista));
    if (L != NULL) L->head = NULL; // lista vazia

    return L;
}

// Função: cheia
// Entrada: Ponteiro para uma lista
// Saída: 1 se a lista está cheia, 0 caso contrário
// Pré-requisito: N/A
// Pós-requisito: Verifica se a lista está cheia e retorna 1 se estiver cheia, 0 caso contrário
int cheia(Lista *L)
{
    return 0;
}

// Função: vazia
// Entrada: Ponteiro para uma lista
// Saída: 1 se a lista está vazia, 0 caso contrário
// Pré-requisito: N/A
// Pós-requisito: Verifica se a lista está vazia e retorna 1 se estiver vazia, 0 caso contrário
int vazia(Lista *L)
{
    if (L->head == NULL) return 1;
    else return 0;
}

// Função: inserir
// Entrada: Ponteiro para uma lista, valor a ser inserido
// Saída: 1 se a inserção for bem-sucedida, 0 caso contrário
// Pré-requisito: N/A
// Pós-requisito: Insere um novo nó com o valor fornecido na lista, mantendo a ordem crescente dos elementos. Retorna 1 se a inserção for bem-sucedida, 0 caso contrário.
int inserir(Lista *L, int X)
{
    Node *Paux, *Pant; // Ponteiros auxiliares
    Node *P; // Ponteiro para o novo nó

    // Se a lista está cheia, não pode inserir
    if (cheia(L)) return 0;

    // Cria o novo nó e verifica se é válido
    P = newNode();
    if (P == NULL) return 0;
    P->info = X;

    Paux = L->head;
    Pant = NULL;
    // Busca a possível posição de inserção
    while (Paux != NULL) {
        Pant = Paux;
        Paux = Paux->next;
    }

    // Elemento já existente na lista
  //  if (Paux != NULL && Paux->info == X) return 0;

    if (Paux != L->head) {
        // Caso 1: Nó inserido no interior da lista (cauda?)
        Pant->next = P;
        P->next = Paux;
    } else {
        // Caso 2: Nó inserido na primeira posição (cabeça)
        L->head = P;
        P->next = Paux;
    }

    return 1;
}

// Função: remover
// Entrada: Ponteiro para uma lista, valor a ser removido
// Saída: 1 se a remoção for bem-sucedida, 0 caso contrário
// Pré-requisito: N/A
// Pós-requisito: Remove o nó com o valor fornecido da lista, mantendo a ordem dos elementos. Retorna 1 se a remoção for bem-sucedida, 0 caso contrário.
int remover(Lista *L, int X)
{
    Node *Paux, *Pant;

    Paux = L->head;
    Pant = NULL;

    // Busca o elemento a ser removido
    while (Paux != NULL && Paux->info < X) {
        Pant = Paux;
        Paux = Paux->next;
    }

    if (Paux != NULL && Paux->info == X) {
        // Encontrei o elemento e vou retirá-lo
        if (Paux != L->head) {
            Pant->next = Paux->next;
        } else {
            L->head = Paux->next;
        }
        deleteNode(Paux);
        return 1; // true, deu certo
    } else { // Não encontrei o elemento
        return 0; // false, não achou
    }
}

// Função: comprimento_cauda
// Entrada: Ponteiro para um nó, valor atual do comprimento
// Saída: Comprimento da lista (número de elementos)
// Pré-requisito: N/A
// Pós-requisito: Calcula o comprimento da lista recursivamente usando a técnica de recursão de cauda. Retorna o comprimento da lista.
int comprimento_cauda(Node *P, int n)
{
    if (P == NULL) return n;
    else {
        return comprimento_cauda(P->next, n+1);
    }
}

// Função: comprimento_auxiliar
// Entrada: Ponteiro para um nó
// Saída: Comprimento da lista (número de elementos)
// Pré-requisito: N/A
// Pós-requisito: Calcula o comprimento da lista recursivamente. Retorna o comprimento da lista.
int comprimento_auxiliar(Node *P)
{
    if (P == NULL) return 0;
    else {
        // Tem ao menos um elemento apontado pelo ponteiro P
        return (1 + comprimento_auxiliar(P->next));
    }
}

// Função: comprimento
// Entrada: Ponteiro para uma lista
// Saída: Comprimento da lista (número de elementos)
// Pré-requisito: N/A
// Pós-requisito: Calcula o comprimento da lista chamando a função comprimento_cauda. Retorna o comprimento da lista.
int comprimento(Lista *L)
{
    Node *P;
    int comp;

    P = L->head;
    comp = comprimento_cauda(P, 0);

    return comp;
}

// Função: pertence_auxiliar
// Entrada: Valor a ser verificado, ponteiro para um nó
// Saída: 1 se o valor pertence à lista, 0 caso contrário
// Pré-requisito: N/A
// Pós-requisito: Verifica se o valor pertence à lista recursivamente. Retorna 1 se o valor pertence à lista, 0 caso contrário.
int pertence_auxiliar(char X, Node *P)
{
    if (P == NULL) return 0; // false
    else if (P->info == X) return 1; // true
    else pertence_auxiliar(X, P->next);
}

// Função: pertence
// Entrada: Valor a ser verificado, ponteiro para uma lista
// Saída: 1 se o valor pertence à lista, 0 caso contrário
// Pré-requisito: N/A
// Pós-requisito: Verifica se o valor pertence à lista chamando a função pertence_auxiliar. Retorna 1 se o valor pertence à lista, 0 caso contrário.
int pertence(char X, Lista *L)
{
    return pertence_auxiliar(X, L->head);
}


int ultimo_aux(Node *P){
    if(P== NULL)return 0;
    if(P->next==NULL) return P->info;
    else return ultimo_aux(P->next);

}
int ultimo(Lista *L){

    if(L->head == NULL) return 0;
    if(L->head->next == NULL) return L->head->info;

    return ultimo_aux(L->head->next);
}

int soma_aux(Node *P){

    if(P==NULL) return 0;
    else{
        int som= P->info+soma_aux(P->next);
        return som;}
}
int soma(Lista *L){

     return soma_aux(L->head);
}
int somaImpar_aux(Node *P){
    if(P==NULL) return 0;
    else if(P->info%2==0) {
        return somaImpar_aux(P->next);}        
            int som=P->info+somaImpar_aux(P->next);
            return som;
    
}
int somaImpar(Lista *L){
    return somaImpar_aux(L->head);
}


int nesimo_aux(Node *P, int n){
    if(P==NULL) return 0;
    else if(n==1) return P->info;
    else return nesimo_aux(P->next, n-1);
}

int nesimo(Lista *L, int n){
    return nesimo_aux(L->head,n);
}


// Função: imprimir
// Entrada: Ponteiro para uma lista
// Saída: N/A
// Pré-requisito: N/A
// Pós-requisito: Imprime os elementos da lista na saída padrão.
void imprimir(Lista *L)
{
    Node *Paux;
    Paux = L->head;

    while (Paux != NULL) {
        printf("%d ", Paux->info);
        Paux = Paux->next;
    }
    printf("\n");
}

// Função: destruir
// Entrada: Ponteiro para uma lista
// Saída: N/A
// Pré-requisito: N/A
// Pós-requisito: Libera a memória alocada para a lista e todos os seus nós.
void destruir(Lista *L)
{
    Node *Paux;

    while(!vazia(L)) {
        Paux = L->head;
        L->head = Paux->next;
        deleteNode(Paux);
    }

    free(L);
}



int main()
{
    Lista *L;

    // Criar a lista
    L = criar();
    if (L == NULL) {
        printf("Erro ao criar a lista\n");
        exit(1);
    }
    inserir(L,2);
    inserir(L,4);
    inserir(L,7);
    inserir(L,3);
    inserir(L,1);
    inserir(L,8);
    inserir(L,10);
    inserir(L,0);
    imprimir(L);
    
    int x;
    int ul = ultimo(L);
    int som=0, somI=0;
    int nes=0;
    som = soma(L);
    nes = nesimo(L,4);
    somI = somaImpar(L);
    printf("\nSoma:%d",som);
    printf("\nSomaImpar:%d",somI);
    printf("\nNesimo:%d",nes);
    printf("\nUltimo:%d",ul);
    printf("\nComprimento:%d\n",comprimento(L));
    printf("Digite um numero para saber se pertence a lista:");
    scanf("%d",&x);
    if(pertence(x,L)==1){
        printf("pertence");
    } else printf("nao pertence");
    


    destruir(L);

    return 0;
}

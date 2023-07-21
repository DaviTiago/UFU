#include <stdlib.h>
#include <stdio.h>

// declaracao do no(node) da lista encadeada simples
struct node {
    char info;
    struct node *next;
};

// definicao do tipo Node
typedef struct node Node;

// declaracao da lista em si
struct lista {
    Node *head;
};

// definicao do tipo Lista
typedef struct lista Lista;

// Função: newNode
// Entrada: N/A
// Saída: Ponteiro para um novo nó alocado dinamicamente
// Pré-requisito: N/A
// Pós-requisito: Retorna um ponteiro para um novo nó alocado dinamicamente
Node *newNode()
{
    Node *n;

    // Se nao puder alocar, retorna NULL
    n = malloc(sizeof(Node));

    return n;
}

// Função: deleteNode
// Entrada: Ponteiro para um nó
// Saída: N/A
// Pré-requisito: N/A
// Pós-requisito: Libera a memória alocada para o nó, se não for nulo
void deleteNode(Node *n)
{
    if (n != NULL) free(n);
}

// Função: criar
// Entrada: N/A
// Saída: Ponteiro para uma nova lista alocada dinamicamente
// Pré-requisito: N/A
// Pós-requisito: Retorna um ponteiro para uma nova lista alocada dinamicamente,
//               com o campo 'head' inicializado como NULL
Lista *criar()
{
    Lista *L;

    L = malloc(sizeof(Lista));
    if (L != NULL) L->head = NULL; // lista vazia
    
    return L;
}

// Função: cheia
// Entrada: Ponteiro para uma lista
// Saída: 0
// Pré-requisito: N/A
// Pós-requisito: Retorna 0 (lista nunca está cheia)
int cheia(Lista *L)
{
    return 0;
}

// Função: vazia
// Entrada: Ponteiro para uma lista
// Saída: 1 se a lista estiver vazia, 0 caso contrário
// Pré-requisito: N/A
// Pós-requisito: Retorna 1 se a lista estiver vazia (campo 'head' é NULL),
//               0 caso contrário
int vazia(Lista *L)
{
    if (L->head == NULL) return 1;
    else return 0;
}

// Função: inserir
// Entrada: Ponteiro para uma lista, valor a ser inserido
// Saída: 1 se a inserção for bem-sucedida, 0 caso contrário
// Pré-requisito: A lista não está cheia
// Pós-requisito: Insere um novo nó com o valor fornecido na lista, de forma ordenada,
//                mantendo a ordem crescente dos elementos. Retorna 1 se a inserção for
//                bem-sucedida (nó adicionado), 0 caso contrário (elemento já existente)
int inserir(Lista *L, char X)
{
    Node *Paux, *Pant; // Ponteiros auxiliares
    Node *P; // Ponteiro para o novo node
    
    // Se a lista esta cheia, nao pode inserir
    if (cheia(L)) return 0;

    // Cria o novo node e verifica se eh valido
    P = newNode();
    if (P == NULL) return 0;
    P->info = X;

    Paux = L->head;
    Pant = NULL;
    // Busca a possivel posicao de insercao
    while (Paux != NULL && Paux->info < X) {
        Pant = Paux;
        Paux = Paux->next;
    }

    // Elemento ja existente na lista
    if (Paux != NULL && Paux->info == X) return 0;

    if (Paux != L->head) {
        // Caso 1: Node inserido no interior da lista
        // (cauda?)
        Pant->next = P;
        P->next = Paux;
    } else {
        // Caso 2: Node inserido na primeira posicao
        // (cabeca)
        L->head = P;
        P->next = Paux;
    }

    return 1;
}

// Função: remover
// Entrada: Ponteiro para uma lista, valor a ser removido
// Saída: 1 se a remoção for bem-sucedida, 0 caso contrário
// Pré-requisito: N/A
// Pós-requisito: Remove o nó correspondente ao valor fornecido da lista,
//                se ele existir. Retorna 1 se a remoção for bem-sucedida,
//                0 caso contrário.
int remover(Lista *L, char X)
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
        // encontrei o elemento e vou retira-lo
        if (Paux != L->head) {
            Pant->next = Paux->next;
        } else {
            L->head = Paux->next;
        }
        deleteNode(Paux);
        return 1;    // true, deu certo
    } else { // nao encontrei o elemento
        return 0;    // false, nao achou
    }
}

// Função: imprimir
// Entrada: Ponteiro para uma lista
// Saída: N/A
// Pré-requisito: N/A
// Pós-requisito: Imprime os elementos da lista
void imprimir(Lista *L)
{
    Node *Paux;
    Paux = L->head;

    while (Paux != NULL) {
        printf("%c ", Paux->info);
        Paux = Paux->next;
    }
    printf("\n");
}

// Função: destruir
// Entrada: Ponteiro para uma lista
// Saída: N/A
// Pré-requisito: N/A
// Pós-requisito: Libera a memória alocada para a lista e seus nós
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
    
    inserir(L, 'D'); // Inserir 'D' na lista
    imprimir(L); // Imprimir lista: D
    inserir(L, 'C'); // Inserir 'C' na lista
    imprimir(L); // Imprimir lista: C D
    inserir(L, 'E'); // Inserir 'E' na lista
    imprimir(L); // Imprimir lista: C D E
    inserir(L, 'A'); // Inserir 'A' na lista
    imprimir(L); // Imprimir lista: A C D E
    inserir(L, 'B'); // Inserir 'B' na lista
    imprimir(L); // Imprimir lista: A B C D E

    remover(L, 'D'); // Remover 'D' da lista
    imprimir(L); // Imprimir lista: A B C E

    remover(L, 'E'); // Remover 'E' da lista
    imprimir(L); // Imprimir lista: A B C

    printf("%d\n", remover(L, 'A')); // Remover 'A' da lista e imprimir 1 (sucesso)
    imprimir(L); // Imprimir lista: B C

    printf("%d\n", remover(L, 'F')); // Remover 'F' (que não existe) da lista e imprimir 0 (falha)
    imprimir(L); // Imprimir lista: B C
    
    destruir(L); // Liberar memória alocada para a lista
    
    return 0;
}

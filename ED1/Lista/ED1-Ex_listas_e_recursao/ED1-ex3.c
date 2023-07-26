// Função: soma_aux
// Entrada: Ponteiro para um nó (P)
// Saída: Soma dos valores armazenados em todos os nós da lista (caso a lista não seja vazia), ou 0 (caso a lista seja vazia)
// Pré-requisito: N/A
// Pós-requisito: Calcula recursivamente a soma dos valores armazenados em todos os nós da lista, percorrendo a lista encadeada.
int soma_aux(Node *P) {
    if (P == NULL) return 0;
    else {
        int sum = P->info + soma_aux(P->next);
        return sum; 
    }
}

// Função: soma
// Entrada: Ponteiro para uma lista (L)
// Saída: Soma dos valores armazenados em todos os nós da lista (caso a lista não seja vazia), ou 0 (caso a lista seja vazia)
// Pré-requisito: N/A
// Pós-requisito: Calcula a soma dos valores armazenados em todos os nós da lista, chamando a função auxiliar "soma_aux".
int soma(Lista *L) {
    return soma_aux(L->head); 
}

// Função: somaImpar_aux
// Entrada: Ponteiro para um nó (P)
// Saída: Soma dos valores ímpares armazenados em todos os nós da lista (caso a lista não seja vazia), ou 0 (caso a lista seja vazia)
// Pré-requisito: N/A
// Pós-requisito: Calcula recursivamente a soma dos valores ímpares armazenados em todos os nós da lista, percorrendo a lista encadeada.
int somaImpar_aux(Node *P) {
    if (P == NULL) return 0; 
    else if (P->info % 2 == 0) {
        return somaImpar_aux(P->next); 
    } else {
        int sum = P->info + somaImpar_aux(P->next); 
        return sum; 
    }
}

// Função: somaImpar
// Entrada: Ponteiro para uma lista (L)
// Saída: Soma dos valores ímpares armazenados em todos os nós da lista (caso a lista não seja vazia), ou 0 (caso a lista seja vazia)
// Pré-requisito: N/A
// Pós-requisito: Calcula a soma dos valores ímpares armazenados em todos os nós da lista, chamando a função auxiliar "somaImpar_aux".
int somaImpar(Lista *L) {
    return somaImpar_aux(L->head); 
}

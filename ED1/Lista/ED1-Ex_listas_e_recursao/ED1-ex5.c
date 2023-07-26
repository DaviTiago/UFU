// Função: nesimo_aux
// Entrada: Ponteiro para um nó (P), e o número n (posição desejada)
// Saída: Valor armazenado no n-ésimo nó da lista (caso exista), ou 0 (caso não exista n-ésimo nó ou a lista seja vazia)
// Pré-requisito: N/A
// Pós-requisito: Realiza uma busca recursiva para encontrar o valor armazenado no n-ésimo nó da lista.
int nesimo_aux(Node *P, int n) {
    if (P == NULL) return 0; 
    else if (n == 1) return P->info; 
    else return nesimo_aux(P->next, n - 1); 
}

// Função: nesimo
// Entrada: Ponteiro para uma lista (L), e o número n (posição desejada)
// Saída: Valor armazenado no n-ésimo nó da lista (caso exista), ou 0 (caso não exista n-ésimo nó ou a lista seja vazia)
// Pré-requisito: N/A
// Pós-requisito: Realiza a busca pelo n-ésimo nó da lista, chamando a função auxiliar "nesimo_aux".
int nesimo(Lista *L, int n) {
    return nesimo_aux(L->head, n);
}

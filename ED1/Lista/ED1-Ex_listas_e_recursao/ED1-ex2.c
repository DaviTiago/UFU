// Função: ultimo_aux
// Entrada: Ponteiro para um nó (P)
// Saída: Valor armazenado no último nó da lista (caso a lista não seja vazia), ou 0 (caso a lista seja vazia)
// Pré-requisito: N/A
// Pós-requisito: Retorna o valor armazenado no último nó da lista, percorrendo a lista recursivamente até encontrar o último nó.
int ultimo_aux(Node *P) {
    if (P == NULL) return 0; // Se o nó for nulo (fim da lista), retorna 0 indicando que a lista está vazia.
    if (P->next == NULL) return P->info; // Se o próximo nó for nulo, este é o último nó, retorna o valor armazenado nele.
    else return ultimo_aux(P->next); // Caso contrário, chama recursivamente a função para o próximo nó da lista.
}

// Função: ultimo
// Entrada: Ponteiro para uma lista (L)
// Saída: Valor armazenado no último nó da lista (caso a lista não seja vazia), ou 0 (caso a lista seja vazia)
// Pré-requisito: N/A
// Pós-requisito: Retorna o valor armazenado no último nó da lista, chamando a função auxiliar "ultimo_aux" para percorrer a lista.
int ultimo(Lista *L) {
    if (L->head == NULL) return 0; 

    if (L->head->next == NULL) return L->head->info;  

// Função: soma_aux
// Entrada: Ponteiro para um nó (P)
// Saída: Soma dos valores armazenados nos nós da lista (caso a lista não seja vazia), ou 0 (caso a lista seja vazia)
// Pré-requisito: N/A
// Pós-requisito: Retorna a soma dos valores armazenados nos nós da lista, percorrendo a lista recursivamente.
    return ultimo_aux(L->head->next);
}


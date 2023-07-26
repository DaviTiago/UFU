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
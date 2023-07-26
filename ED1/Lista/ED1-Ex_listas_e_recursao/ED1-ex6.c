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
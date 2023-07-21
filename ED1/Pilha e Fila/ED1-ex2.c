//ex2
#include <stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 5 //TAMANHO

typedef struct pilha{
    int topo;
    char elementos[MAX];
}Pilha;

Pilha *criar(){
    Pilha *p;
    p=malloc(sizeof(Pilha));
    if(p!=NULL){
        p->topo=-1;
    }
        return p;
}

    void destruir(Pilha *p){
        if(p!=NULL) 
        free(p);
    }
    int cheia(Pilha *p){
        if(p->topo== (MAX-1))
        return 1; // True
        else return 0;// False
    }
    int vazia(Pilha *p){
        if(p->topo == -1) return 1; // True 
        else return 0;
    }

    int empilhar(Pilha *p, char x){
        if(cheia(p)==1)
        return 0; //false
        else{
            p->topo=p->topo+1;
            p->elementos[p->topo]=x;
            return 1;
        }
    }

    int desempilhar(Pilha *p, char *x){
        if(vazia(p)==1)
        return 0; //false
        else{
            *x=p->elementos[p->topo];
            p->topo=p->topo-1;
            return 1;
        }
    }
    /*
    Entrada: Uma pilha e a chave 
    Saida: 1 se a chave for removida, 0 caso contrário
    Pré-requisito: Uma pilha auxiliar, chave passada por referência, as pilhas devem ser validas;
    Pós-requisito: pilha principal alterada */
    int remove_chave(Pilha *p, char *chave){
        Pilha *aux;
        aux=criar();
        char c;
        int encontrar = 0;
        
        if(vazia(p)==1)
        return 0; //false,vazia

        else{
            while(desempilhar(p,&c)==1){
                if(c == *chave){
                    encontrar=1;
                    break;
                }
                if(empilhar(aux,c)==0)
                return 0; //false, aux cheia
            }
                if(encontrar == 1){
                    while(desempilhar(aux,&c)==1){
                        if(empilhar(p,c)==0)
                            return 0;// false, p cheia
                    }
                    return 1;// true, deu tudo certo chave removida
                } 
                else{
                    while(desempilhar(aux,&c)==1){
                        if(empilhar(p,c)==0) 
                        return 0;// false, p cheia

                    }
                    return 0;//Chave não encontrada
                }
            
        }
    }

    int main(){
        Pilha *P;
        Pilha *aux;
        char c,t, chave;
        int teste,teste2;
        
        P=criar();

        for(int i=0; i<MAX; i++){
            printf("Digite um elemento:");
            scanf(" %c", &c);
            teste=empilhar(P,c);
            //printf("Teste = %d\n", teste);
        }
        printf("Se deseja remover algum elemento digite [s],[n]\n");
        scanf(" %c", &t);
        if(t=='s' || t=='S'){
            printf("Digite a chave que sera removida:");
            scanf(" %c", &chave);
            teste2=remove_chave(P,&chave);
            if(teste2 == 1){
                printf("CHAVE REMOVIDA COM SUCESSO!!!!\n");
            }else printf("Chave não encontrada\n");

            
        }

        while(desempilhar(P,&c)==1){
            printf(" %c\n",c); 
        }
        destruir(P);

        return 0;
    }

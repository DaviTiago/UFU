#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define QUANTIDADE 21

//Nome: Davi Tiago Soares. Nº: 12211BSI240.

int main() {
    char temp[12];
    char lista[QUANTIDADE][12] = { "Vinicius", "Guilherme", "Vitor", "Lucas", "Igor", "Joao", "Pedro", "Abel", "Luiz", "Wemerson", "Rafael", "Pablo", "Saint", "Thais", "Matheus", "Douglas", "Gabriel", "Viviane", "Reginaldo", "Jose", "Leonardo" };
    
    printf("Antes de ordenar:\n=====================\n");
    for (int i = 0; i < QUANTIDADE; i++)
    printf("%s\n",lista[i]);

    for(int i=0; i<QUANTIDADE; i++){
        for(int j=0; j<QUANTIDADE; j++){
            if(strcmp(lista[i],lista[j])<0){
                strcpy(temp,lista[i]);
                strcpy(lista[i],lista[j]);
                strcpy(lista[j],temp);

            }
        }
    }
    printf("\n\nApos ordenar:\n=====================\n");
    for (int i = 0; i < QUANTIDADE; i++)
    printf("%s\n",lista[i]);
    return 0;
}
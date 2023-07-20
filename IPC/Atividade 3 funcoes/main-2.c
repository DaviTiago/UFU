#include<stdlib.h>
#include<stdio.h>
#include<math.h>

//Nome: Davi Tiago Soares. Nª: 12211BSI240

int eleva(int n){
    int soma=0;
    for(int i =1; i<= n; i++){
    soma += i*i;
}
return soma;
}

int main(){
int n;
    printf("Digite um numero\n");
    scanf("%d",&n);
    printf("A soma dos primeiros n numeros elevados a si proprios eh: %d",eleva(n));
    
return 0;
}
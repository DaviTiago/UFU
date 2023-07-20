#include<stdio.h>
#include<stdlib.h>

//Nome: Davi Tiago Soares. Nª: 12211BSI240

/*A função abaixo utiliza um loop para caucular cada termo da sequência, 
percorrendo os números de 1 a n-1, na qual n é o número do termo que se deve calcular;
Porem a função não consegue cumprir o a proposta,pois não consegue retornar o termo 100 por ser maior do que a capacidadade do long long int. */
 long long int FibonacciIterativo(int n) {
 long long int i, x = 0, y = 1, aux;
for (i = 1; i < n; i++) {
aux = x;
x = x + y;
y = aux;
}
return x;
}
/*A função abaixo usa a recursão para calcular o termo solicitado da sequência. 
Porem a função não consegue ser finalizda, devido a grande quantidade de processamento necessária, 
tendo que ser chamada novamente caso o numero passado não seja 0 ou 1, 
agora com n-1 e n-2 como parâmetros e os resultados dessas chamadas são somados 
e retornados como o resultado da função, 
assim consumindo muito tempo e memória tentando calcular um resultado muito grande.

*/
int FibonacciRecursivo(int n) {
if (n == 0 || n == 1) {
return n;
} else {
return FibonacciRecursivo(n-1) + FibonacciRecursivo(n-2);
}
}

int main( ) {
 int i;
 for (i = 1; i < 100; i++)
   printf("\n termo %d: %llu", i, FibonacciIterativo(i));
 for (i = 1; i < 100; i++)
   printf("\n termo %d: %llu", i, FibonacciRecursivo (i));
return 0;}
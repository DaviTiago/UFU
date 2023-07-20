#include<stdlib.h>
#include<stdio.h>
#include<math.h>
//Nome: Davi Tiago Soares. Nª: 12211BSI240

int crescente(int n) {
  if (n >= 0) {
    crescente(n - 1);
    printf("%d ", n);
     }
}

int decrescente(int n) {
  if (n >= 0) {
    printf("%d ", n);
    decrescente(n - 1);
  }
}
int main()
{

  printf("\n crescente: "); crescente(15);
  printf("\n descrescente: "); decrescente(15);
  return 0;
}



#include<stdio.h>

int main() {
   int altura, base, area;
 
   printf("\nEscribe la altura : ");
   scanf("%d", &altura);
 
   printf("\nEscribe la base : ");
   scanf("%d", &base);
 
   area = altura * base;
   printf("\nEl area del rectangulo es : %d", area);
 
   return (0);
}
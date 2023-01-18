#include<stdio.h>  
int main()  
{  
    int n, c, fact = 1;  
    n = 6;  
  
    for(c = 1; c <= n; c++)  
    {  
        fact = fact * c;  
    }  
  
    printf("Factorial de %d es %d\n", n, fact);  
  
    return 0;  
}  
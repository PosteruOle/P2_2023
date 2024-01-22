/*
Zadatak 10: Napisati funkciju koja ispituje da li je dati ceo broj n stepen broja 2. Koristiti bitovske operatore.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void greska(){
    fprintf(stderr,"-1\n");
    exit(EXIT_FAILURE);
}

void print_bits(int x){
    unsigned mask=1;
    mask<<=sizeof(int)*8-1;
    printf("\n--------------------\n");
    for(int i=1;i<=sizeof(int)*8;i++){
        if((mask & x)!=0)
          printf("1");
        else 
          printf("0");
        mask>>=1;    
    }
    printf(" <- %d", x);
    printf("\n--------------------\n");
}

int suma_bitova(int x){
   int count=0;
   unsigned mask=1;
   for(int i=1;i<=sizeof(int)*8;i++){
      if((mask & x)!=0)
        count++;
      mask<<=1;  
   }
   return count;
}

int main(){

    int x;
    printf("Unesite ceo broj x: \n");
    scanf("%d", &x);
    print_bits(x);
    if(suma_bitova(x)==1)
      printf("Jeste!\n");
    else
      printf("Nije!\n");  
    
    return 0;
}

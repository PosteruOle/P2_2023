/*
Zadatak 12: a) Napisati program koji odredjuje najveci pozitivan broj koji se moze zapisati istim binarnim
ciframa kao dati broj. Koristiti bitovske operatore. Sa standarnog ulaza se unosi broj, a na standarni
izlaz se ispisuje rezultat.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void error(){
    fprintf(stderr,"-1\n");
    exit(EXIT_FAILURE);
}

void print_bits(unsigned x){
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
    printf(" <- %u\n", x);
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

unsigned generate(int n){
   unsigned result=0;
   unsigned mask=1 << (sizeof(unsigned)*8-1);
   for(int i=1;i<=n;i++){
      result|=mask;
      mask>>=1;
   }
   return result;
}

int main(){
    
    unsigned x;
    printf("Unesite ceo broj x: \n");
    scanf("%u", &x);
    print_bits(x);
    print_bits(generate(suma_bitova(x)));

    return 0;
}

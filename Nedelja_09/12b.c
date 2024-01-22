/*
Zadatak 12: b) Napisati funkciju koja odredjuje najmanji pozitivan broj koji se moze zapisati istim binarnim ciframa kao
dati broj. Koristiti bitovske operatore. Sa standarnog ulaza se unosi broj, a na standarni izlaz se
ispisuje rezultat.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void error(){
    fprintf(stderr,"-1\n");
    exit(EXIT_FAILURE);
}

unsigned sum_of_bits(int x){
   int count=0;
   unsigned mask=1;
   for(int i=1;i<=32;i++){
      if((x & mask)!=0)
        count++;
      mask<<=1;  
   }
   return count;
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
    printf("\n--------------------\n");
}

unsigned min(unsigned suma){
   unsigned result=0;
   unsigned mask=1;
   while(suma!=0){
      result|=mask;
      suma--;
      mask<<=1;
   }
   return result;  
}

int main(){

   int x;
   printf("Unesite ceo broj x: \n");
   scanf("%d", &x);
   printf("\n---------------------------\n");
   print_bits(x);
   printf("Minimalan broj koji mozemo da formiramo je: %u.\n", min(sum_of_bits(x)));
   print_bits(min(sum_of_bits(x)));
    
   return 0;
}

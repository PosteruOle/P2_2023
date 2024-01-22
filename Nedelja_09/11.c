/*
Zadatak 11 Napisati program koja broji koliko se puta kombinacija 11 (dve uzastopne jedinice) pojavljuje u
binarnom zapisu celog broja x. Broj x se unosi sa standarnog ulaza, a rezultat se ispisuje na standarni izlaz.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void error(){
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
    printf("\n--------------------\n");
}

int total(int x){
   int count=0;
   unsigned mask=3;
   for(int i=1;i<=sizeof(int)*8-1;i++){
      if((mask&x)==mask)
        count++;
      //x>>=1;
      mask<<=1;  
   }
   return count;
}

int main(){

    int x;
    printf("Unesite ceo broj x: \n");
    scanf("%d", &x);
    print_bits(x);
    printf("Ukupan broj pojavljivanja iznosi: %d\n", total(x));

    return 0;
}

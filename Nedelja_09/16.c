/*
Zadatak 16: Sa standarnog ulaza ucitava se neoznacen ceo broj x, neoznacen ceo broj n i niz od n celih
neoznacenih brojeva (n ≤ 32). Odrediti neoznacen ceo broj y koji se dobija na sledeci nacin: porede se i-ti
bit broja x i i-ti bit i-tog broja niza. Ukoliko su jednaki na i-to mesto broja y se postavlja bit 1, a inace se
postavlja 0 (ukoliko i-ti broj niza ne postoji, podrazumevati da je vrednost odgovarajuceg bita 0). Ispisati broj
y na standardni izlaz. U slucaju greske ispisati -1 na standardni izlaz.
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

int main(){

   int x;
   int n;
   int y=0;
   int *niz;
   printf("Unesite ceo broj x: \n");
   scanf("%u", &x);
   printf("Unesite pozitivan ceo broj n: \n");
   scanf("%d", &n);
   if(n<0 || n>=32)
     error();
   
   niz=(int *)calloc(32, sizeof(int));
   if(niz==NULL)
     error();

   printf("Unesite n celih brojeva: \n");
   for(int i=0;i<n;i++){
      scanf("%d", &niz[i]);
   }
   printf("\n-----------------------------------\n");
   unsigned mask=1;
   for(int i=0;i<32;i++){
      if((x&mask)==(niz[i]&mask))
        y|=mask;
      mask<<=1;  
   }
   printf("y = %u\n", y);

   free(niz);
    return 0;
}

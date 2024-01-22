/*
Zadatak 15: Sa standardnog ulaza se unosi ceo broj n (n ≤ 32), a zatim i niz od n neoznacenih celih brojeva.
Formirati neoznaceni ceo broj x tako sto se na i-ti bit broja x postavlja vrednost i-tog bita i-tog broja niza.
Broj x ispisati na standardni izlaz. Bitove broja citati od pozicija manje tezine ka pozicijama vece tezine.
Podrazumevana vrednost bitova broja x je 0. U slucaju greske ispisati −1 na standardni izlaz.
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

int n;
   int *niz;
   int x=0;
   printf("Unesite ceo broj n: \n");
   scanf("%d", &n);
   
   if(n<=0 || n>=32)
     error();
   
   niz=(int *)malloc(n*sizeof(int));  
   if(niz==NULL)
     error();
   
   printf("Unesite n celih brojeva: \n");
   for(int i=0;i<n;i++){
      scanf("%d", &niz[i]);
   }
   printf("\n-------------------------\n");
   unsigned mask=1;
   for(int i=0;i<n;i++){
      unsigned tmp=niz[i] & mask;
      x|=tmp;
      mask<<=1;
   }
   printf("x = %d\n", x);
   
   free(niz);
   
   return 0;
}

/*
Zadatak 7: Napisati funkciju unsigned invert_bits(unsigned x, int p, int n) koja invertuje n bitova
broja x pocevsi od pozicije p. Testirati funkciju pozivom u main-u, pri cemu se brojevi x, p i n unose sa
standarnog ulaza. Proveriti da li su brojevi p i p + n u odgovaraju ́cem opsegu i ispisati poruku o gresci ako
nisu. Na standarni izlaz ispisati bitove unesenog broja x i bitove novodobijenog broja.
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
    printf("\n--------------------\n");
}

unsigned invert_bits(unsigned x, int p, int n){
   unsigned mask=1;
   mask<<=p;
   for(int i=1;i<=n;i++){
      x^=mask;
      mask<<=1;
   } 
   return x;
}

int main(){

    unsigned x;
    int p;
    int n;
    printf("Unesite ceo broj x, p i n: \n");
    scanf("%u %d %d", &x, &p, &n);
    if(p<0 || p>=32 || n<0 || p+n>32)
      greska();
    print_bits(x);
    x=invert_bits(x, p, n);
    print_bits(x);  


    return 0;
}

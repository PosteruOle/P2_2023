/*
Zadatak 5: Napisati funkciju unsigned get_bits(int x, int p, int n) koja vraca broj dobijen od broja
x tako da mu je izdvojeno n bita pocev od pozicije p, a ostalo su 0. Testirati funkciju pozivom u main-u, pri
cemu se brojevi x, p i n unose sa standarnog ulaza. Proveriti da li su brojevi p i p+n u odgovarajucem opsegu
i ispisati poruku o gresci ako nisu. Na standarni izlaz ispisati bitove unesenog broja x i bitove novodobijenog
broja.
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

unsigned get_bits(int x, int p, int n){
   unsigned result=0;
   
   /* 
   unsigned mask=~0;
   mask<<=n;
   mask=~mask;
   mask<<=p;
   x&=mask;
   return x;
   */
   
   unsigned mask=1;
   
   mask<<=p;
   for(int i=1;i<=n;i++){
      result|=(mask&x);
      mask<<=1;
   }
   
   return result;
}

int main(){

    int x;
    int p;
    int n;
    printf("Unesit redom brojeve x, p i n: \n");
    scanf("%d %d %d", &x, &p, &n);
    if(p<0 || p>=32 || n<0 || p+n>=32)
      greska();
    print_bits(x);
    unsigned final=get_bits(x, p, n);
    print_bits(final);  
    
     

    return 0;
}

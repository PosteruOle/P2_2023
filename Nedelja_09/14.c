/*
Zadatak 14: Napisati funkciju koja na osnovu neoznacenog broja x formira nisku s koji sadrzi heksadekadni
zapis broja x, koristeci algoritam za brzo prevodjenje binarnog u heksadekadni zapis (svake 4 binarne cifre se
zamenjuju jednom odgovarajucom heksadekadnom cifrom).
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

void ispisi(unsigned x){
   unsigned mask=15;
   mask<<=(sizeof(unsigned)*8-4);
   for(int i=1;i<=sizeof(unsigned)*2;i++){
      unsigned tmp=mask & x;
      tmp>>=(sizeof(unsigned)*2-i)*4;
      if(tmp<10)
        printf("%d", tmp);
      else
        printf("%c", 'A'+tmp-10);
          
      mask>>=4;
   }
   printf("\n");
}

int main(){


    unsigned x;
    scanf("%u", &x);
    ispisi(x);

    return 0;
}

/*
Zadatak 8 Napisati funkciju unsigned right_rotate(unsigned x, int n) koja vrsi rotaciju neoznacenog
broja x za n pozicija u desno. Testirati funkciju pozivom u main-u. Brojevi x i n se unose sa standarnog
ulaza. Na standarni izlaz ispisati binarnu reprezentaciju broja x i novodobijnog broja. Ukoliko je broj n
negativan ispisati poruku o gresci.
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

unsigned right_rotate(unsigned x, int n){
    unsigned mask1=1;
    unsigned mask2=1 << (sizeof(int)*8-1);
    for(int i=1;i<=n;i++){
       if((mask1 & x)!=0){
         x>>=1;
         x|=mask2;
       } else {
         x>>=1;
       }
    }
    return x;
}

int main(){

    unsigned x;
    int n;
    printf("Unesite redom brojeve x i n: \n");
    scanf("%u %d", &x, &n);
    if(n>=32)
      n=n%32;
    print_bits(x);
    x=right_rotate(x, n);
    print_bits(x);

    return 0;
}

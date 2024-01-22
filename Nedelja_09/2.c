/*
Zadatak 2: Napisati program koji proverava da li je na k-tom mestu jedinica u celom broju x. Celi brojevi
k (neoznacen ceo broj) i x se unose sa standarnog ulaza. Pozicija se broji od najmanje tezine ka najvecoj
pocevsi od 0. Ukoliko pozicija nije u dobrom opsegu ispisati poruku o gresci.
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

int check(unsigned x, int k){
   unsigned mask=1;
   mask<<=k;
   if((mask & x)!=0)
     return 1;
   return 0;
}

int main(){

    unsigned x;
    int k;
    printf("Unesite redom brojeve x i k: \n");
    scanf("%u %d", &x, &k);
    if(k<0 || k>=32)
      greska();
    //printf("")  
    print_bits(x);
    int flag=check(x, k);
    if(flag)
      printf("Jeste!\n");
    else
      printf("Nije!\n");      
      
   
    return 0;
}

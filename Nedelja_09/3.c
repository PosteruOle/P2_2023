/*
Zadatak 3: Napisati program koji postavlja na k-to mestu jedinicu u celom broju x. Celi brojevi k (neoznacen
ceo broj) i x se unose sa standarnog ulaza. Pozicija se broji od najmanje tezine ka najvecoj pocevsi od 0.
Ukoliko pozicija nije u dobrom opsegu ispisati poruku o gresci.
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

unsigned set_one(unsigned x, int k){
    unsigned mask=1;
    mask<<=k;
    //x|=mask;
    x=x | mask;
    return x;
}

unsigned set_zero(unsigned x, int k){
    unsigned mask=1;
    mask<<=k;
    x=x & (~mask);
    return x;
}


int main(){

    unsigned x;
    int k;
    printf("Unesite redom brojeve x i k: \n");
    scanf("%u %d", &x, &k);
    if(k<0 || k>=32)
      greska();
    printf("\n------------------------------------------\n");  
    printf("sizeof(char) = %ld\n", sizeof(char));
    printf("sizeof(short) = %ld\n", sizeof(short));
    printf("sizeof(int) = %ld\n", sizeof(int));  
    printf("sizeof(unsigned) = %ld\n", sizeof(unsigned));
    printf("sizeof(float) = %ld\n", sizeof(float));
    printf("\n------------------------------------------\n");
    print_bits(x);
    x=set_zero(x, k);
    print_bits(x);
    printf("x=%u\n", x);  

    return 0;
}

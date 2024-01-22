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

int total(unsigned x){
    int count=0;
    for(int i=1;i<=(sizeof(int)*8)/2;i++){
        if((x& 3)==3)
          count++;
        x>>=2;  
    }
    return count;
}

int main(){

    unsigned x;
    printf("Unesite ceo broj x: \n");
    scanf("%u", &x);
    int count=total(x);
    print_bits(x);
    printf("Pronadjeno je %d trazenih pojavljivanja!\n", count);

    return 0;
}
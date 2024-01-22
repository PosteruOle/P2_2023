/*
Zadatak 1: Napisati funkciju print_bits koja stampa bitove u zapisu datog celog broja x.
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
    for(int i=1;i<=sizeof(int)*8;i++){
       if((mask & x) !=0)
         printf("1");
       else
         printf("0");
       mask>>=1;      
    }
    printf("\n");
}

int main(){

    int x;
    printf("Unesite ceo broj x: \n");
    scanf("%d", &x);
    print_bits(x);

    return 0;
}

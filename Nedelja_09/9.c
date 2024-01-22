/*
Zadatak 9: Napisati funkciju unsigned mirror(unsigned x) koja obrce zapis broja x. Testirati funkciju
pozivom u main-u. Broj x se unosi sa standarnog ulaza. Na standarni izlaz ispisati binarnu reprezentaciju
broja x i novodobijnog broja.
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

unsigned mirror(unsigned x){
    unsigned result=0;
    unsigned mask1=1;
    unsigned mask2=1<<(sizeof(unsigned)*8-1);
    for(int i=1;i<=sizeof(unsigned)*4;i++){
       unsigned tmp1=(x & mask1);
       unsigned tmp2=(x & mask2);
       tmp1>>=i-1;
       tmp2<<=i-1;
       result|=tmp1 << (sizeof(unsigned)*8 - i);
       result|=tmp2 >> (sizeof(unsigned)*8 - i);
       
       mask1<<=1;
       mask2>>=1;
    }
    return result;
}

int main(){

    unsigned x;
    printf("Unesite broj x: \n");
    scanf("%u", &x);
    print_bits(x);
    x=mirror(x);
    print_bits(x);    
    
    

    return 0;
}

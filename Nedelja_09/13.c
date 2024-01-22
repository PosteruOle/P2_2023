/*
Zadatak 13 Napisati program koji ispisuje zapis datog broja u pokretnom zarezu (napomena: moze se koristit
unija koja sadrzi float i long).
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

union broj
{
    int ibroj;
    float fbroj;
};

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

    union broj x;
   
    printf("Unesite broj x:\n");
    scanf("%f", &x.fbroj);
    
    print_bits(x.ibroj);

    return 0;
}

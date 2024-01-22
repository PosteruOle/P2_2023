#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

int main(){

    Cvor *glava=NULL;
    int x;
    int count=0;
    printf("Unesite elemente liste: \n");
    glava=ucitaj_listu(glava, stdin);
    printf("Unesite ceo broj x: \n");
    scanf("%d", &x);

    Cvor *tmp=glava;
    while(tmp!=NULL){
        if(tmp->vrednost==x)
          count++;
        tmp=tmp->sledeci;  
    }
    printf("Broj pojavljivanja elementa x iznosi: %d.\n", count);

    oslobodi_listu(glava);

    return 0;
}
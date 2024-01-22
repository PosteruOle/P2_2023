#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

int main(){

    Cvor *glava=NULL;
    int x;
    glava=ucitaj_listu(glava, stdin);
    scanf("%d", &x);

    Cvor *tmp=glava;
    int pozicija=-1;
    int i=1;
    while(tmp!=NULL){
        if(tmp->vrednost==x){
            pozicija=i;
            break;
        }
        tmp=tmp->sledeci;
        i++;
    }
    
    if(pozicija==-1)
      printf("Element se ne nalazi u listi!\n");
    else 
      printf("Prvo pojavljivanje je na poziciji %d!\n", pozicija);

    oslobodi_listu(glava);

    return 0;
}
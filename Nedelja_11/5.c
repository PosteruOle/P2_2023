#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

void umetni(Cvor** glava){
    if(*glava==NULL)
      return;
    if((*glava)->sledeci==NULL)
      return;

    Cvor *tmp=napravi_cvor((*glava)->vrednost-(*glava)->sledeci->vrednost);
    tmp->sledeci=(*glava)->sledeci;
    (*glava)->sledeci=tmp;
    umetni(&(*glava)->sledeci->sledeci);     
}

int main(){

    Cvor *glava=NULL;
    printf("Lista: \n");
    glava=ucitaj_listu(glava, stdin);
    umetni(&glava);
    ispisi_listu(glava);
    
    oslobodi_listu(glava);

    return 0;
}
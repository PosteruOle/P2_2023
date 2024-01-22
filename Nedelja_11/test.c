#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

void izmeni_listu(Cvor** lista){
    if(*lista==NULL)
      return;
    if((*lista)->sledeci==NULL)
      return;

    Cvor *tmp1=(*lista)->sledeci;
    Cvor *tmp2=(*lista)->sledeci->sledeci;
    Cvor *tmp3=*lista;    
    *lista=tmp1;
    (*lista)->sledeci=tmp3;
    (*lista)->sledeci->sledeci=tmp2;
    izmeni_listu(&(*lista)->sledeci->sledeci);
}


int main(){

    Cvor* lista=NULL;
    lista=ucitaj_listu(lista, stdin);
    ispisi_listu(lista);
    printf("\n----------------------------\n");
    izmeni_listu(&lista);
    ispisi_listu(lista);
    printf("\n----------------------------\n");
    oslobodi_listu(lista);

    return 0;
}
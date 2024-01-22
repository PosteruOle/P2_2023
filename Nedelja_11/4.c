#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

int check(Cvor *lista, int x){
    if(lista==NULL)
      return 0;

    if(lista->vrednost==x)
      return 1;
    else
      return check(lista->sledeci, x);    
}

Cvor* izbaci(Cvor *lista1, Cvor *lista2){
    if(lista1==NULL)
      return NULL;
    if(lista2==NULL)
      return lista1;
    if(check(lista2, lista1->vrednost)){
      Cvor* tmp=lista1->sledeci;
      free(lista1);
      return izbaci(tmp, lista2);
    }
    lista1->sledeci=izbaci(lista1->sledeci, lista2);
    return lista1;
}

int main(){

    Cvor *glava1=NULL;
    Cvor *glava2=NULL;
    printf("Lista 1: \n");
    glava1=ucitaj_listu(glava1, stdin);
    printf("Lista 2: \n");
    glava2=ucitaj_listu(glava2, stdin);

    glava1=izbaci(glava1, glava2);
    ispisi_listu(glava1);

    oslobodi_listu(glava1);
    oslobodi_listu(glava2);

    return 0;
}
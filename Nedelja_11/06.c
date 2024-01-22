#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

Cvor *ucesljaj(Cvor* glava1, Cvor *glava2){
    if(glava1==NULL && glava2==NULL)
      return NULL;
    if(glava1==NULL)
      return glava2;
    if(glava2==NULL)
      return glava1;
    Cvor *glava3=napravi_cvor(glava1->vrednost);
    glava1=glava1->sledeci;
    Cvor *tmp=glava3;
    //int redni=2;
    while(glava1!=NULL && glava2!=NULL){
        if(glava1->vrednost<=glava2->vrednost){
          tmp->sledeci=napravi_cvor(glava1->vrednost);
          tmp=tmp->sledeci;
          glava1=glava1->sledeci;
          //redni=2;
        } else {
          tmp->sledeci=napravi_cvor(glava2->vrednost);
          tmp=tmp->sledeci;
          glava2=glava2->sledeci;
          //redni=1;
        } 
    }

    while(glava1!=NULL){
        tmp->sledeci=napravi_cvor(glava1->vrednost);
        tmp=tmp->sledeci;
        glava1=glava1->sledeci;
    }

    while(glava2!=NULL){
        tmp->sledeci=napravi_cvor(glava2->vrednost);
        tmp=tmp->sledeci;
        glava2=glava2->sledeci;
    }

    return glava3;      
}

int main(){
    
    Cvor *glava1=NULL;
    Cvor *glava2=NULL;

    printf("Unosimo elemente prve liste: \n");
    glava1=ucitaj_listu(glava1, stdin);
    printf("Unosimo elemente druge liste: \n");
    glava2=ucitaj_listu(glava2, stdin);
    printf("Lista nakom ucesljavanja izgleda ovako!\n");
    Cvor* glava3=ucesljaj(glava1, glava2);
    ispisi_listu(glava3);

    return 0;
}
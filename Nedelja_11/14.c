#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

void izmeni(Cvor **glava, int prethodnik){
    if(*glava==NULL)
      return;
    if((*glava)->sledeci==NULL)
      return;  
    
    if(prethodnik==0){
      izmeni(&(*glava)->sledeci, (*glava)->vrednost);
      return;
    }

    if((*glava)->vrednost==prethodnik+(*glava)->sledeci->vrednost){
        Cvor *tmp=(*glava)->sledeci;
        prethodnik=(*glava)->vrednost;
        free(*glava);
        *glava=tmp;
        izmeni(glava, prethodnik);
        return;
    } else {
        izmeni(&(*glava)->sledeci, (*glava)->vrednost);
    } 
}

int main(){

    Cvor* glava=NULL;
    glava=ucitaj_listu(glava, stdin);
    izmeni(&glava, NULL);
    ispisi_listu(glava);

    oslobodi_listu(glava);

    return 0;
}
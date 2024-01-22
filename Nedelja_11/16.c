#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

void izmeni_listu(Cvor **glava){
   if(*glava==NULL)
     return;

   if((*glava)->vrednost%2==1){
      Cvor *tmp=(*glava)->sledeci;
      free(*glava);
      *glava=tmp;
      izmeni_listu(glava);
      return;
   }
   izmeni_listu(&(*glava)->sledeci);  
}

int main(){

    Cvor *glava=NULL;
    //int k;
    printf("Unosimo elemente liste: \n");
    glava=ucitaj_listu(glava, stdin);
    //printf("Unesite ceo broj k: \n");
    //scanf("%d", &k);
    izmeni_listu(&glava);
    ispisi_listu(glava);

    oslobodi_listu(glava);

    return 0;
}
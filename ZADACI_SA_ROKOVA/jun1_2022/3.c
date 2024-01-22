#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

void izmeni_listu(Cvor **glava, int k, int p){
   if(*glava==NULL)
     return;
   
   if((*glava)->sledeci==NULL)
     return;
   
   if(abs((*glava)->vrednost+(*glava)->sledeci->vrednost)%k==p){
      Cvor *novi1=napravi_cvor(0);
      Cvor *novi2=napravi_cvor(0);
      Cvor *tmp=(*glava)->sledeci;
      (*glava)->sledeci=novi1;
      novi1->sledeci=novi2;
      novi2->sledeci=tmp;
      izmeni_listu(&(*glava)->sledeci->sledeci->sledeci, k, p);
      return;
   }

   izmeni_listu(&(*glava)->sledeci, k, p);
}

int main(){

    Cvor *glava=NULL;
    int k;
    int p;
    scanf("%d %d", &k, &p);
    glava=ucitaj_listu(glava, stdin);
    izmeni_listu(&glava, k, p);
    ispisi_listu(glava);

    oslobodi_listu(glava);

    return 0;
}
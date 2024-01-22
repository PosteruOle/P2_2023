#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

void izmeni_listu(Cvor **glava, int x, int y, int z){
    if(*glava==NULL)
      return;

    if((*glava)->sledeci==NULL)
      return;

    if((*glava)->vrednost==x && (*glava)->sledeci->vrednost==y){
      Cvor *tmp=napravi_cvor(z);
      tmp->sledeci=(*glava)->sledeci;
      (*glava)->sledeci=tmp;
      izmeni_listu(&(*glava)->sledeci->sledeci, x, y, z);
      return;  
    }
    izmeni_listu(&(*glava)->sledeci, x, y, z);    
}

int main(){

   Cvor *glava=NULL;
   int x;
   int y;
   int z;
   printf("Unesite elemente liste: \n");
   glava=ucitaj_listu(glava,stdin);
   printf("Unesite brojeve x, y i z: \n");
   scanf("%d %d %d", &x, &y, &z);
   izmeni_listu(&glava, x, y, z);
   ispisi_listu(glava);

   oslobodi_listu(glava);

   return 0;
}

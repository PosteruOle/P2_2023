#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

void izmeni_listu(Cvor **glava, int x){
    if(*glava==NULL)
      return;
    if((*glava)->sledeci==NULL)
      return;

    if((*glava)->vrednost+(*glava)->sledeci->vrednost==x){
      Cvor* tmp=(*glava)->sledeci->sledeci;
      free((*glava)->sledeci);
      free(*glava);
      *glava=tmp;
      izmeni_listu(glava, x);
      return;
    }
    izmeni_listu(&(*glava)->sledeci, x);    
}

int main(){

    Cvor *glava=NULL;
    int x;
    printf("Unosite elemente liste: \n");
    glava=ucitaj_listu(glava, stdin);
    printf("Unesite ceo broj x: \n");
    scanf("%d", &x);
    izmeni_listu(&glava, x);
    ispisi_listu(glava);
 
    //oslobodi_listu(glava);

    return 0;
}
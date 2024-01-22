#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

void izmeni_listu(Cvor **lista, int k){
    if(*lista==NULL)
      return;
    if((*lista)->sledeci==NULL)
      return;

    if(abs((*lista)->vrednost-(*lista)->sledeci->vrednost)==k || ((*lista)->vrednost+(*lista)->sledeci->vrednost)==k){
      Cvor *new_one=napravi_cvor(-1);
      new_one->sledeci=(*lista)->sledeci;
      (*lista)->sledeci=new_one;
      izmeni_listu(&new_one->sledeci, k);
      return;
    }
    izmeni_listu(&(*lista)->sledeci, k);    
}

int main(){

    Cvor *glava=NULL;
    int k;
    printf("Unesite elemente liste: \n");
    glava=ucitaj_listu(glava, stdin);
    clearerr(stdin);
    printf("Unesite ceo broj k: \n");
    scanf("%d", &k);
    ispisi_listu(glava);
    printf("\n------------------------\n");
    printf("Lista nakon modifikacije izgleda ovako: \n");
    izmeni_listu(&glava, k);
    ispisi_listu(glava);


    oslobodi_listu(glava);

    return 0;
}
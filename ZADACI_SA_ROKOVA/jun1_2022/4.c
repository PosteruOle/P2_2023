#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stabla.h"

void paran_broj_suseda(Cvor *glava, Cvor *predak){
    if(glava==NULL)
      return;

    paran_broj_suseda(glava->levo, glava);
    paran_broj_suseda(glava->desno, glava);
    
    int susedi;
    if(predak!=NULL){
      susedi=1;
      if(glava->levo!=NULL)
        susedi++;
      if(glava->desno!=NULL)
        susedi++;

      if(susedi%2==0)
        printf("%d ", glava->vrednost);    
    } else {
      susedi=0;
      if(glava->levo!=NULL)
        susedi++;
      if(glava->desno!=NULL)
        susedi++;

      if(susedi%2==0)
        printf("%d ", glava->vrednost);
    }

}

int main(){

    Cvor *glava=NULL;
    int x;
    while(scanf("%d", &x)!=EOF){
        dodaj_u_stablo(&glava, x);
    }

    paran_broj_suseda(glava, NULL);
    
    oslobodi(glava);

    return 0;
}
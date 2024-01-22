#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stabla.h"

int broj_cvorova(Cvor *koren){
   if(koren==NULL)
      return 0;
   
   if(koren->levo==NULL && koren->desno==NULL)
      return 1;
    
   int l=broj_cvorova(koren->levo);
   int r=broj_cvorova(koren->desno);
   return l+r+1; 
}

int broj_listova(Cvor *koren){
   if(koren==NULL)
     return 0;

   if(koren->levo==NULL && koren->desno==NULL)
     return 1;

   int l=broj_listova(koren->levo);
   int r=broj_listova(koren->desno);
   return l+r;    
}

int dubina(Cvor *glava, int level){
    if(glava==NULL)
      return level;
    
    level++;
    int l=dubina(glava->levo, level);
    int r=dubina(glava->desno, level);
    if(l>r)
      return l;
    else 
      return r;    
}

int zbir(Cvor* glava){
    if(glava==NULL)
      return 0;

    if(glava->levo==NULL && glava->desno==NULL)
      return glava->broj;  
    
    int l=zbir(glava->levo);
    int r=zbir(glava->desno);

    return l+r+glava->broj;
}

int main(){
    
    Cvor *glava=NULL;
    ucitaj_stablo(&glava, stdin);
    printf("Broj cvorova u stablo iznosi: %d.\n", broj_cvorova(glava));
    printf("Broj litova u stablu iznosi: %d.\n", broj_listova(glava));
    int level=dubina(glava, -1);
    printf("Dubina stabla iznosi: %d.\n", level);
    printf("\n-------------------------------------\n");
    printf("Zbir svih cvorova stabla iznosi: %d.\n", zbir(glava));

    oslobodi_stablo(glava);

    return 0;
}
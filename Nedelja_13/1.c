#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stabla.h"

Cvor* pretrazi_stablo(Cvor* koren, int broj){
    if(koren==NULL){
       return NULL; 
    }

    if(koren->broj==broj)
      return koren;
    
    if(koren->broj<broj)
      return pretrazi_stablo(koren->desno, broj);
    else 
      return pretrazi_stablo(koren->levo, broj);    
}

Cvor* pronadji_najmanji(Cvor* koren){
    if(koren==NULL){
        return NULL;
    }

    if(koren->levo==NULL && koren->desno==NULL){
        return koren;   
    }

    Cvor *l=pronadji_najmanji(koren->levo);
    Cvor *d=pronadji_najmanji(koren->desno);

    if(l!=NULL && d!=NULL){
      
      if(koren->broj<=l->broj && koren->broj <= d->broj)
        return koren;
      else if(l->broj <= koren->broj && l->broj <= d->broj)
        return l;
      else
        return d;    

    } else if(l!=NULL) {
      return koren->broj <= l->broj ? koren : l;  
    } else if(d!=NULL) {
      return koren->broj <= d->broj ? koren : d;  
    } else {
      return koren;  
    }
}

Cvor* pronadji_najveci(Cvor* koren){
    if(koren==NULL){
        return NULL;
    }

    if(koren->levo==NULL && koren->desno==NULL){
        return koren;   
    }

    Cvor *l=pronadji_najveci(koren->levo);
    Cvor *d=pronadji_najveci(koren->desno);

    if(l!=NULL && d!=NULL){
      
      if(koren->broj >= l->broj && koren->broj >= d->broj)
        return koren;
      else if(l->broj >= koren->broj && l->broj >= d->broj)
        return l;
      else
        return d;    

    } else if(l!=NULL) {
      return koren->broj >= l->broj ? koren : l;  
    } else if(d!=NULL) {
      return koren->broj >= d->broj ? koren : d;  
    } else {
      return koren;  
    }
}

int main(){

    Cvor *glava=NULL;
    Cvor *min=NULL;
    Cvor* max=NULL;
    int x;
    ucitaj_stablo(&glava, stdin);
    clearerr(stdin);
    printf("\n--------------------------\n");
    printf("Trazimo broj: ");
    scanf("%d", &x);
    if(pretrazi_stablo(glava, x)!=NULL)
      printf("Broj se nalazi u stablu!\n");
    else 
      printf("Broj se ne nalazi u stablu!\n"); 
    
    printf("\n--------------------------\n");
    min=pronadji_najmanji(glava);
    max=pronadji_najveci(glava);
    if(min!=NULL)
      printf("Najmanji: %d.\n", min->broj);

    if(max!=NULL)
      printf("Najveci: %d.\n", max->broj);

    oslobodi_stablo(glava);
    //oslobodi_stablo(min);
    //oslobodi_stablo(max);    
    
    return 0;
}
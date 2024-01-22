/*
Zadatak 2 Dva binarna stabla su identicna ako su ista po strukturi i sadrzaju tj. ako oba korena imaju isti
sadrzaj i identicna odgovaraju ́ca podstabla. Napisati funkciju int identitet(Cvor* koren1, Cvor* koren2) koja
proverava da li su binarna stabla koren1 i koren2 koja sadrze cele brojeve identicna, a zatim i program koji
testira njen rad. Elemente pojedinacnih stabla unositi sa standardnog ulaza sve do pojave broja 0.
U slucaju greske na standardni izlaz za greˇske ispisati -1.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stabla.h"

int identitet(Cvor *glava1, Cvor* glava2){
    if(glava1==NULL && glava2==NULL){
        return 1;
    }

    if(glava1==NULL || glava2==NULL){
        return 0;
    }

    if(glava1->broj!=glava2->broj)
      return 0;
    
    int l=identitet(glava1->levo, glava2->levo);
    if(l==0)
      return l;
    
    int r=identitet(glava1->desno, glava2->desno);
    return r;
}

int main(){

    Cvor *glava1=NULL;
    Cvor *glava2=NULL;
    int x;
    printf("Ucitavamo elemente prve liste: \n");
    while(1){
        scanf("%d", &x);
        if(x==0)
          break;
        dodaj_u_stablo(&glava1, x);  
    }
    printf("\nUcitavamo elemente druge liste: \n");
    while(1){
        scanf("%d", &x);
        if(x==0)
          break;
        dodaj_u_stablo(&glava2, x);  
    }
    if(identitet(glava1, glava2))
      printf("Stabla su identicna!\n");
    else 
      printf("Stabla nisu identicna!\n");  

    return 0;
}
/*
Zadatak 5 Elementi binarnog pretrazivackog stabla su celi brojevi i ucitavaju se sa standardnog ulaza sve do
kraja ulaza. Odrediti broj cvorova stabla koji su jednaki zbiru svojih suseda. Smatramo da su susedi nekom
cvoru njegovi direktni potomci i njegov prvi predak. Koren nema pretka, pa su njegovi susedi samo njegovi
direktni potomci. Cvor koji je list nema potomke, pa je njegov sused samo njegov direktan predak. Rezultat
ispisati na standardni izlaz.
U slucaju greske na standardni izlaz za greske ispisati -1.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stabla.h"

int count=0;

void pretrazi_stablo(Cvor* glava, Cvor *predak){
    if(glava==NULL){
        return;
    }
    
    if(predak==NULL){
      if(glava->levo!=NULL && glava->desno!=NULL){
        if(glava->broj==(glava->levo->broj+glava->desno->broj))
          count++;
      
      } else if(glava->levo!=NULL) {
        if(glava->broj==(glava->levo->broj))
          count++;
        
      } else if(glava->desno!=NULL){
        if(glava->broj==(glava->desno->broj))
          count++;
      } 
    } else {
      if(glava->levo!=NULL && glava->desno!=NULL){
        if(glava->broj==(predak->broj+glava->levo->broj+glava->desno->broj))
          count++;
        //return;  
      } else if(glava->levo!=NULL) {
        if(glava->broj==(predak->broj+glava->levo->broj))
          count++;
        //return;
      } else if(glava->desno!=NULL){
        if(glava->broj==(predak->broj+glava->desno->broj))
          count++;
        //return;
      } else {
        if(glava->broj==predak->broj)
          count++;
        //return;
      }  
    }


    pretrazi_stablo(glava->levo, glava);
    pretrazi_stablo(glava->desno, glava);
}

int main(){

    Cvor *glava=NULL;
    ucitaj_stablo(&glava, stdin);
    printf("\n-------------------------------\n");
    pretrazi_stablo(glava, NULL);
    printf("Broj cvorova koji su jednaki sumi svojih suseda iznosi: %d.\n", count);

    return 0;
}
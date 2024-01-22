/*
Zadatak 4: Napisati program koji ispisuje sadrzaj binarnog pretrazivackog stabla po nivoima. Elementi sta-
bla se ucitavaju sa standardnog ulaza sve do kraja ulaza.
U slucaju greske na standardni izlaz za greske ispisati -1.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stabla.h"

int level=-1;

void visina_stabla(Cvor *glava, int nivo){
   if(glava==NULL){
      return;
   } 
   
   nivo++;
   if(nivo>level)
     level=nivo;

   visina_stabla(glava->levo, nivo);
   visina_stabla(glava->desno, nivo);  
}

void elementi_na_odredjenom_nivou(Cvor *koren, int level, int current_level){
    if(koren==NULL){
        return;
    }

    if(current_level==level){
        printf("%d ", koren->broj);
    }

    elementi_na_odredjenom_nivou(koren->levo, level, current_level+1);
    elementi_na_odredjenom_nivou(koren->desno, level, current_level+1);
}

int main(){

    Cvor *glava=NULL;
    ucitaj_stablo(&glava, stdin);
    printf("\n--------------------------\n");
    visina_stabla(glava, -1);
    for(int i=0;i<=level;i++){
        printf("%d. nivo:", i);
        elementi_na_odredjenom_nivou(glava, i, 0);
        printf("\n");
    }

    return 0;
}
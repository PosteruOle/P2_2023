/*
Zadatak 7: Napisati funkciju koja iz datoteke karakteri.txt ucitava karaktere i smesta ih u binarno pre-
trazivacko stablo. Uz svaki karakter cuvati i broj pojavljivanja karaktera u datoteci. Ispisati na standardni
izlaz karakter koji se pojavljuje najve ́ci broj puta u datoteci i odgovarajuci broj pojavljivanja.
U slucaju greske na standardni izlaz za greske ispisati -1.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "stabla.h"

void greska(){
    fprintf(stderr,"-1\n");
    exit(EXIT_FAILURE);
}

typedef struct Cvor{
  char c;
  int freq;
  struct Cvor* levo;
  struct Cvor* desno;
} Cvor;

Cvor* napravi_cvor(char c){
    Cvor *novi=malloc(sizeof(Cvor));
    if(novi==NULL)
      greska();
    novi->c=c;
    novi->freq=1;
    novi->levo=NULL;
    novi->desno=NULL;
    return novi;  
}

void dodaj_u_stablo(Cvor** koren, int c){
    if(*koren==NULL){
        *koren=napravi_cvor(c);
        return;
    }

    if((*koren)->c == c)
      (*koren)->freq++;
    else if((*koren)->c < c)  
      dodaj_u_stablo(&(*koren)->desno, c);
    else 
      dodaj_u_stablo(&(*koren)->levo, c);  

}

void ucitaj_stablo(Cvor** koren, FILE *f){
    if(f==NULL)
      greska();

    char x;
    while(fscanf(f,"%c", &x)!=EOF){
        dodaj_u_stablo(koren, x);
    } 
}

Cvor* pretrazi_stablo(Cvor* koren){
    if(koren==NULL){
        return NULL;
    }

    if(koren->levo==NULL && koren->desno==NULL){
        return koren;   
    }

    Cvor *l=pretrazi_stablo(koren->levo);
    Cvor *d=pretrazi_stablo(koren->desno);

    if(l!=NULL && d!=NULL){
      
      if(koren->freq >= l->freq && koren->freq >= d->freq)
        return koren;
      else if(l->freq >= koren->freq && l->freq >= d->freq)
        return l;
      else
        return d;    

    } else if(l!=NULL) {
      return koren->freq >= l->freq ? koren : l;  
    } else if(d!=NULL) {
      return koren->freq >= d->freq ? koren : d;  
    } else {
      return koren;  
    }  

}

int main(){

    Cvor *glava=NULL;
    FILE *f=fopen("karakteri.txt", "r");
    if(f==NULL)
      greska();

    ucitaj_stablo(&glava, f);
    Cvor* max=pretrazi_stablo(glava);
    if(max!=NULL)
      printf("'%c': %d\n", max->c, max->freq);

    fclose(f);

    return 0;
}
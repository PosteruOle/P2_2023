#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

void f1(Cvor **glava, int p){
    if(*glava==NULL)
      return;
    
    if(p%2==0){
      Cvor *tmp=(*glava)->sledeci;
      free(*glava);
      *glava=tmp;
      f1(glava, p+1);
    } else {
      f1(&(*glava)->sledeci, p+1);
    }  
}

int main(){
    
    Cvor* glava=NULL;
    glava=ucitaj_listu(glava, stdin);
    f1(&glava, 1);
    ispisi_listu(glava);

    oslobodi_listu(glava);

    return 0;
}
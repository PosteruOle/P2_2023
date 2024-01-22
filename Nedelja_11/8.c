#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

int f7(Cvor **glava){
   if((*glava)->sledeci==NULL)
     return (*glava)->vrednost;
   
   if(abs((*glava)->vrednost)%2==0){
     (*glava)->sledeci->vrednost++;
     return f7(&(*glava)->sledeci);
   } else {
     (*glava)->sledeci->vrednost--;
     return f7(&(*glava)->sledeci);
   }   
}

int main(){

    Cvor *glava=NULL;
    glava=ucitaj_listu(glava, stdin);
    printf("%d\n", f7(&glava));

    oslobodi_listu(glava);


    return 0;
}
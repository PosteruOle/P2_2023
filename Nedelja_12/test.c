#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stabla.h"

int main(){

    Cvor *glava=NULL;
    ucitaj_stablo(&glava, stdin);
    
    printf("Infiksni ispis: ");
    ispisi_stablo_infiksno(glava);

    printf("\nPrefiksni ispis: ");
    ispisi_stablo_prefiksno(glava);

    printf("\nPostfiksni ispis: ");
    ispisi_stablo_postfiksno(glava);

    return 0;
}
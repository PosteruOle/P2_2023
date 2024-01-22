#include "stabla.h"


void greska(){
    fprintf(stderr,"-1\n");
    exit(EXIT_FAILURE);
}

Cvor* napravi_cvor(int broj){
    Cvor *novi=malloc(sizeof(Cvor));
    if(novi==NULL)
      greska();

    novi->broj=broj;
    novi->levo=NULL;
    novi->desno=NULL;
    return novi;  
}

void dodaj_u_stablo(Cvor** koren, int broj){
    if(*koren==NULL){
        Cvor* novi=napravi_cvor(broj);
        *koren=novi;
        return;
    }

    if((*koren)->broj<broj){
        dodaj_u_stablo(&(*koren)->desno, broj);
    } else {
        dodaj_u_stablo(&(*koren)->levo, broj);
    }
}

void ucitaj_stablo(Cvor** koren, FILE* f){
    if(f==NULL){
        greska();
    }

    int x;
    while(fscanf(f, "%d", &x)!=EOF){
        dodaj_u_stablo(koren, x);
    }
}

void ispisi_stablo_infiksno(Cvor* koren){
    if(koren==NULL){
        return;
    }

    ispisi_stablo_infiksno(koren->levo);
    printf("%d ", koren->broj);
    ispisi_stablo_infiksno(koren->desno);
}

void ispisi_stablo_prefiksno(Cvor* koren){
    if(koren==NULL){
        return;
    }

    printf("%d ", koren->broj);
    ispisi_stablo_prefiksno(koren->levo);
    ispisi_stablo_prefiksno(koren->desno);
}

void ispisi_stablo_postfiksno(Cvor* koren){
    if(koren==NULL){
        return;
    }

    ispisi_stablo_postfiksno(koren->levo);
    ispisi_stablo_postfiksno(koren->desno);
    printf("%d ", koren->broj);
}

void ispisi_stablo(Cvor* koren, FILE* f){
    if(f==NULL){
        greska();
    }

    if(koren==NULL){
        return;
    }

    ispisi_stablo(koren->levo, f);
    printf("%d ", koren->broj);
    ispisi_stablo(koren->desno, f);
}

void oslobodi_stablo(Cvor* koren){
    if(koren==NULL){
        return;
    }

    if(koren->levo==NULL && koren->desno==NULL){
        free(koren);
        return;
    }

    oslobodi_stablo(koren->levo);
    oslobodi_stablo(koren->desno);
    free(koren);
}
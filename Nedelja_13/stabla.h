#ifndef __STABLA_H__
#define __STABLA_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Cvor{
  int broj;
  struct Cvor* levo;
  struct Cvor* desno;
} Cvor;

void greska();

Cvor* napravi_cvor(int broj);

void dodaj_u_stablo(Cvor** koren, int broj);

void ucitaj_stablo(Cvor** koren, FILE* ulaz);

void ispisi_stablo_infiksno(Cvor* koren);

void ispisi_stablo_prefiksno(Cvor* koren);

void ispisi_stablo_postfiksno(Cvor* koren);

void ispisi_stablo(Cvor* koren, FILE* f);

void oslobodi_stablo(Cvor* koren);


#endif
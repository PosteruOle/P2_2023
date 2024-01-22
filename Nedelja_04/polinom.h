#ifndef __POLINOM_H__
#define __POLINOM_H__

#include <stdio.h>
#include <stdlib.h>

void greska();

int* unos(int* n);

void ispis_polinoma(int* a, int n);

int suma_polinoma(int* a, int n, int* b, int m, int** c);

void mnoz_skalarom(int *a, int n, int c);

int vr_poly(int* a, int n, int x);

int mul_poly(int *a, int n, int* b, int m, int** c);




#endif
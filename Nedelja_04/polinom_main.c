#include "polinom.h"

int main(){
    
    int n;
    int m;
    int k;
    int *p1;
    int *p2;
    int *p3;
    int x;
    int c;
    /*
    int* unos(int* n);
    void ispis_polinoma(int* a, int n);
    int suma_polinoma(int* a, int n, int* b, int m, int** c);
    void mnoz_skalarom(int *a, int n, int c);
    int vr_poly(int* a, int n, int x);
    int mul_poly(int *a, int n, int* b, int m, int** c);
    */

    p1=unos(&n);
    ispis_polinoma(p1, n);

    printf("Unesite tacku u kojoj zelite da izracunate vrednost polinoma: \n");
    scanf("%d", &x);
    printf("Vrednost polinoma u unetoj tacki iznosi: %d.\n", vr_poly(p1, n, x));
    printf("\n------------------------------------\n");
    printf("Unosimo vrednost drugog polinoma!\n");
    p2=unos(&m);
    ispis_polinoma(p2, m);
    k=suma_polinoma(p1, n, p2, m, &p3);
    printf("\n------------------------------------\n");
    printf("Zbir unetih polinoma izgleda ovako: \n");
    ispis_polinoma(p3, k);
    printf("\n------------------------------------\n");
    printf("Proizvod unetih polinoma izgleda ovako: \n");
    k=mul_poly(p1, n, p2, m, &p3);
    ispis_polinoma(p3, k);
    printf("\n------------------------------------\n");
    printf("Polinom 1: \n");
    ispis_polinoma(p1, n);
    printf("Unesti skalar kojim zelite da pomnozite koeficijente polinoma p1: \n");
    scanf("%d", &c);
    printf("\n------------------------------------\n");
    printf("Polinom p1 nakon mnozenja skalarom c izgleda ovako: \n");
    mnoz_skalarom(p1, n , c);
    ispis_polinoma(p1, n);

    return 0;
}
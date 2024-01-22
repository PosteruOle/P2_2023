/*
Zadatak 14: Sa standardnog ulaza se uˇcitava ceo broj x, ceo broj n (n ≤ 100), a potom i niz od
n celih brojeva. Napisati rekurzivnu funkciju void f(int a[], int n, int x), koja u nizu a poslavlja na nulu
sve parove susednih elementa ˇciji je zbir (u poˇcetnom nizu) jednak x. Rezultuju ́ci niz ispisati na standardni
izlaz. U sluˇcaju greˇske ispisati -1 na standardni izlaz za greˇske.
Napomena: Zadatak mora biti uradjen rekurzivno. Nije dozvoljeno koriˇs ́cenje statiˇckih i globalnih promenljivih,
menjanje zaglavlja funkcije i pisanje pomo ́cnih funkcija.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void greska(){
  fprintf(stderr,"-1\n");
  exit(EXIT_FAILURE);
}

void f(int* a, int n, int x)
{
  if(n <= 1)
    return;
  
  int a0, a1;
  a0 = a[0];
  a1 = a[1];
  
  f(a+1, n-1, x);
  
  if(a0 + a1 == x){
    a[0] = 0;
    a[1] = 0;
  }
}

int main(){

 int n;
 int x;
 int *niz;
 printf("Unesite ceo broj x: \n");
 scanf("%d", &x);
 printf("Unesite pozitivan ceo broj n: \n");
 scanf("%d", &n);
 if(n<0)
   greska();
   
 niz=(int*)malloc(n*sizeof(int));
 if(niz==NULL)
   greska();
 
 printf("Unesite elemente niza: \n");
 for(int i=0;i<n;i++)
    scanf("%d", &niz[i]);
 
 printf("\n----------------------------\n");
 f(niz, n, x);
 printf("Niz nakon izmene izgleda ovako: \n");   
 for(int i=0;i<n;i++)
    printf("%d ", niz[i]);
 printf("\n");   
 
 free(niz);    

 return 0;
}

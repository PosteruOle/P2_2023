#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void greska(){
  fprintf(stderr,"-1\n");
  exit(EXIT_FAILURE);
}

/*
int maksimum_niza(int* a, int n){
   if(n==1)
     return a[0];
   return a[n-1] > maksimum_niza(a, n-1) ? a[n-1] : maksimum_niza(a, n-1);  
}
*/

//Iskomentarisali na casu! U zakomentarisanoj verziji funkcije dva puta pozivamo isti rekurzivni poziv!
//Proveriti na WebGrade-u da zakomentariana verzija funckije za neke test primere probija zadato vremensko ogranicenje!
int maksimum_niza(int* a, int n){
   if(n==1)
     return a[0];
   int tmp=maksimum_niza(a, n-1);
     
   return a[n-1] >  tmp ? a[n-1] : tmp;  
}

int main(){

 int n;
 int *niz;
 scanf("%d", &n);
 niz=(int*)malloc(n*sizeof(int));
 if(niz==NULL)
   greska();
 for(int i=0;i<n;i++)
    scanf("%d", &niz[i]);
 
 printf("%d\n", maksimum_niza(niz, n));  

 return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include "polinom.h"

void greska(){
    fprintf(stderr,"-1\n"); 
    exit(EXIT_FAILURE);
}

int* unos(int* n){
    printf("Unesite stepen polinoma: \n");
    scanf("%d", n);
    if(n<=0)
      greska();

    int *niz=(int*)malloc((*n+1)*sizeof(int));
    if(niz==NULL)
      greska();
    
    printf("Unesite koeficijente polinoma: \n");
    for(int i=0;i<=*n;i++){
       scanf("%d", &niz[i]);
    }
    
    return niz;
}

void ispis_polinoma(int* a, int n){
    
    printf("\n---------------------------------------\n");
    printf("Ispisujemo prosledjeni polinom: \n");
    
    if(n==0){
        printf("%d\n", a[0]);
        return;
    }

    printf("%d ", a[0]);
    for(int i=1;i<=n;i++){
        if(a[i]<0)
          printf("- %d * x", abs(a[i]));
        else
          printf("+ %d * x", a[i]);
        if(i>1)
          printf("^%d ", i);
        else 
          printf(" ");      
    }
    
    printf("\n");
    printf("\n---------------------------------------\n");
}

int suma_polinoma(int* a, int n, int* b, int m, int** c){
   if(n>m){
     *c=(int*)malloc((n+1)*sizeof(int));
     if(*c==NULL)
       greska();
   } else {
     *c=(int*)malloc((m+1)*sizeof(int));
     if(*c==NULL)
       greska();
   }

   int i=0;
   int j=0;
   int k=0;
   while(i<=n && j<=m){
      (*c)[k]=a[i]+b[j];
      i++;
      j++;
      k++;
   }

   while(i<=n){
     (*c)[k]=a[i];
     i++;
     k++;
   }

   while(j<=m){
     (*c)[k]=b[j];
     k++;
     j++;
   }

   if(n>m)
     return n;
   else 
     return m;  
}

void mnoz_skalarom(int *a, int n, int c){
    for(int i=0;i<=n;i++){
        a[i]*=c;
    }
}

int vr_poly(int* a, int n, int x){
    int result=0;
    for(int i=n;i>=0;i--){
        result=result*x+a[i];
    }
    return result;
}

int mul_poly(int *a, int n, int* b, int m, int** c){
    //int k=n+m;
    *c=(int*)calloc((n+m+1),sizeof(int));
    if(*c==NULL)
      greska();
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            (*c)[i+j]+=a[i]*b[j];
        }
    }
    
    return n+m;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void greska(){
  fprintf(stderr,"-1\n");
  exit(EXIT_FAILURE);
}

int uvecaj(int x){
  return x+1;
}

int kvadriraj(int x){
  return x*x;
}

int negiraj(int x){
  return -x;
}

void modifikuj(int n, int *niz, int (*fp)(int)){
    for(int i=0;i<n;i++){
       //niz[i]=(*f)(niz[i]);
       niz[i]=fp(niz[i]);
    }
}

void stampaj(int n, int *niz){
  for(int i=0;i<n;i++){
     printf("%d ", niz[i]);
  }
  printf("\n");
}


int main(){

 int n;
 int *niz;
 scanf("%d", &n);
 if(n<=0)
   greska();
   
 niz=(int*)malloc(n*sizeof(int));
 if(niz==NULL)
   greska();  

 for(int i=0;i<n;i++)
    scanf("%d", &niz[i]);
    
 printf("\n----------------------\n"); 
 printf("Uvecano: \n");
 modifikuj(n, niz, uvecaj);
 stampaj(n, niz);
 printf("\n----------------------\n");
 
 printf("\n----------------------\n"); 
 printf("Kvadrirano: \n");
 modifikuj(n, niz, kvadriraj);
 stampaj(n, niz);
 printf("\n----------------------\n");
 
 printf("\n----------------------\n"); 
 printf("Negirano: \n");
 modifikuj(n, niz, negiraj);
 stampaj(n, niz);
 printf("\n----------------------\n");     

 free(niz);
 
 return 0;
}

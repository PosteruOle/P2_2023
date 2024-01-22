#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void greska(){
  fprintf(stderr,"-1\n");
  exit(EXIT_FAILURE);
}

void stampaj(int *niz, int n){
  for(int i=0;i<n;i++){
     printf("%d ", niz[i]);
  }
  printf("\n");
}

void insertion_sort(int* niz, int n){
   int i;
   int j;
   for(i=1;i<n;i++){
      int current=niz[i];
      for(j=i; j>0 && current<niz[j-1];j--){
         niz[j]=niz[j-1];
      }
      niz[j]=current;
   }
}

void insertion_sort_reverse(int* niz, int n){
   int i;
   int j;
   for(i=1;i<n;i++){
      int current=niz[i];
      for(j=i; j>0 && current>=niz[j-1];j--){
         niz[j]=niz[j-1];
      }
      niz[j]=current;
   }
}



void selection_sort(int *niz, int n){
  
  for(int i=0;i<n;i++){
     int poz_min=i;
     for(int j=i;j<n;j++){
        if(niz[j]<niz[poz_min])
          poz_min=j;
     }
     
     int tmp=niz[i];
     niz[i]=niz[poz_min];
     niz[poz_min]=tmp;
  }

}

void selection_sort_reverse(int *niz, int n){
  
  for(int i=0;i<n;i++){
     int poz_min=i;
     for(int j=i;j<n;j++){
        if(niz[j]>=niz[poz_min])
          poz_min=j;
     }
     
     int tmp=niz[i];
     niz[i]=niz[poz_min];
     niz[poz_min]=tmp;
  }

}


int main(int argc, char* argv[]){

  if(argc!=2)
    greska();
    
  int n;
  int *niz;  
  printf("Unesite dimenziju niza: \n");  
  scanf("%d", &n);
  
  niz=(int*)malloc(n*sizeof(int));
  if(niz==NULL)
    greska();
  
  printf("Unesite elemente niza: \n");
  for(int i=0;i<n;i++){
     scanf("%d", &niz[i]);
  }
  
  if(strcmp("-i", argv[1])==0)
    insertion_sort(niz, n);
  else if(strcmp("-s", argv[1])==0)
    selection_sort(niz, n);
  else if(strcmp("-ir", argv[1])==0)
    insertion_sort_reverse(niz, n);
  else if(strcmp("-sr", argv[1])==0)
    selection_sort_reverse(niz, n);
  else 
    greska();  
    
  printf("\n-------------------------------------\n");
  printf("Sada cemo modifikovati uneti niz!\n");
  stampaj(niz, n); 
  printf("\n-------------------------------------\n");
       
  /*
  printf("\n-------------------------------------\n");
  printf("Sada cemo modifikovati uneti niz!\n");
  printf("Niz nakon primene selection sort-a izgleda ovako: \n");
  selection_sort(niz, n);
  stampaj(niz, n);
  printf("\n-------------------------------------\n");
  
  printf("\n-------------------------------------\n");
  printf("Sada cemo modifikovati uneti niz!\n");
  printf("Niz nakon primene reverse selection sort-a izgleda ovako: \n");
  selection_sort_reverse(niz, n);
  stampaj(niz, n);
  printf("\n-------------------------------------\n");
  */
   
  free(niz);
  
  return 0;
}

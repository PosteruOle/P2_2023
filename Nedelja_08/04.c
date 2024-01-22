#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 21

void greska(){
    fprintf(stderr,"-1\n");
    exit(EXIT_FAILURE);
}

typedef struct{
  char ime[MAX];
  char prezime[MAX];
  char smer;
  double prosek;
} STUDENT;

void print_students(STUDENT* niz, int n){

    for(int i=0;i<n;i++){
        printf("%s %s %c %.2lf\n", niz[i].ime, niz[i].prezime, niz[i].smer, niz[i].prosek);
    }
}

void transfer(STUDENT* niz, int p, int q){
    STUDENT tmp=niz[p];
    niz[p]=niz[q];
    niz[q]=tmp;
}

int compare(const void* x, const void *y);

void quick_sort(STUDENT* niz, int l, int r){
    if(l>=r)
      return;
    
    int pivot_position=l;
    int i;
    for(i=l+1;i<=r;i++){
        if(niz[i].prosek > niz[l].prosek || (niz[i].prosek == niz[l].prosek && strcmp(niz[i].prezime, niz[l].prezime)<0))
          transfer(niz, i, ++pivot_position);
    }
    transfer(niz, l, pivot_position);

    quick_sort(niz, l, pivot_position-1);
    quick_sort(niz, pivot_position+1, r);
}

int compare(const void* x, const void *y){
   STUDENT s1=*(STUDENT*)x;
   STUDENT s2=*(STUDENT*)x;
   if(s1.prosek>s2.prosek)
     return 1;
   else if(s1.prosek==s2.prosek){
     return strcmp(s1.prezime, s2.prezime);
   } else  
     return -1;  
}

int main(int argc, char* argv[]){
    
    if(argc!=2)
      greska();

    int n;
    STUDENT *niz;
    FILE *f=fopen("studenti.txt", "r");
    if(f==NULL)
      greska();

    fscanf(f, "%d", &n);
    if(n<=0)
      greska();

    niz=(STUDENT*)malloc(n*sizeof(STUDENT));
    if(niz==NULL)
      greska();

    for(int i=0;i<n;i++){
        fscanf(f, "%s %s %c %lf", niz[i].ime, niz[i].prezime, &niz[i].smer, &niz[i].prosek);
    }

    printf("\n-------------------------------------\n");
    printf("Ovddde?!\n");

    if(strcmp(argv[1], "-q")==0)
      quick_sort(niz, 0, n-1);
    else if(strcmp(argv[1], "-qsort")==0)
      qsort(niz, n, sizeof(STUDENT), compare);  

    print_students(niz, n);

    free(niz);      
    fclose(f);    

    return 0;
}
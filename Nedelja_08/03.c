#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void greska(){
    fprintf(stderr,"-1\n");
    exit(EXIT_FAILURE);
}

void print_elements(double *niz, int n){
    for(int i=0;i<n;i++){
        printf("%.2lf ", niz[i]);
    }
    printf("\n");
}

void merge_sort(double *niz, int l, int r, double *help){
    if(l>=r)
      return;

    int s=(l+r)/2;
    merge_sort(niz, l, s, help);
    merge_sort(niz, s+1, r, help);

    int i=l;
    int j=s+1;
    int k=0;
    while(i<=s && j<=r){
        if(niz[i]<niz[j]){
            help[k]=niz[i];
            k++;
            i++;
        } else {
            help[k]=niz[j];
            k++;
            j++;
        }
    } 

    while(i<=s){
        help[k]=niz[i];
        k++;
        i++;
    } 
    while(j<=r){
        help[k]=niz[j];
        k++;
        j++;
    }

    for(i=l, k=0;i<=r;i++, k++){
        niz[i]=help[k];
    }
}

void merge_sort_reverse(double *niz, int l, int r, double *help){
    if(l>=r)
      return;

    int s=(l+r)/2;
    merge_sort_reverse(niz, l, s, help);
    merge_sort_reverse(niz, s+1, r, help);

    int i=l;
    int j=s+1;
    int k=0;
    while(i<=s && j<=r){
        if(niz[i]>=niz[j]){
            help[k]=niz[i];
            k++;
            i++;
        } else {
            help[k]=niz[j];
            k++;
            j++;
        }
    } 

    while(i<=s){
        help[k]=niz[i];
        k++;
        i++;
    } 
    while(j<=r){
        help[k]=niz[j];
        k++;
        j++;
    }

    for(i=l, k=0;i<=r;i++, k++){
        niz[i]=help[k];
    }
}

void transfer(double *niz, int p, int q){
    double tmp=niz[p];
    niz[p]=niz[q];
    niz[q]=tmp;
}

void quick_sort(double *niz, int l, int r){
    if(l>=r)
      return;
    int pivot_position=l;
    int i;
    for(i=l+1;i<=r;i++){
        if(niz[i]<niz[l])
          transfer(niz, i, ++pivot_position);
    }

    transfer(niz, l, pivot_position);

    quick_sort(niz, l, pivot_position-1);
    quick_sort(niz, pivot_position+1, r);  
}

void quick_sort_reverse(double *niz, int l, int r){
    if(l>=r)
      return;

    int pivot_position=l;
    int i;
    for(i=l+1;i<=r;i++){
        if(niz[i]>niz[l])
          transfer(niz, i, ++pivot_position);
    }
    
    transfer(niz, l, pivot_position);

    quick_sort_reverse(niz, l, pivot_position-1);
    quick_sort_reverse(niz, pivot_position+1, r);
}

int compare_acs(const void *x, const void *y){
   double a=*(double*)x;
   double b=*(double*)y;
   if(a>b)
     return 1;
   else if(a==b)
     return 0;
   else
     return -1;    
}

int compare_desc(const void *x, const void *y){
   double a=*(double*)x;
   double b=*(double*)y;
   if(a>b)
     return -1;
   else if(a==b)
     return 0;
   else
     return 1;
}

int main(int argc, char* argv[]){

    if(argc!=2)
      greska();

    int n;
    double *niz;
    printf("Unesite dimenziju niza: \n");
    scanf("%d", &n);

    niz=(double*)malloc(n*sizeof(double));
    if(niz==NULL)
      greska();

    printf("Unesite elemente niza: \n");
    for(int i=0;i<n;i++){
        scanf("%lf", &niz[i]);
    }

    printf("Elementi niza su uspesno uneti!");
    printf("\n--------------------------------\n");

    double *help=(double*)malloc(n*sizeof(double));
    if(help==NULL)
      greska();

    if(strcmp(argv[1], "-m")==0)
      merge_sort(niz, 0, n-1, help);
    else if(strcmp(argv[1], "-mr")==0)
      merge_sort_reverse(niz, 0, n-1, help);
    else if(strcmp(argv[1], "-q")==0)
      quick_sort(niz, 0, n-1);
    else if(strcmp(argv[1], "-qr")==0)
      quick_sort_reverse(niz, 0, n-1); 
    else if(strcmp(argv[1], "-qsort")==0)
      qsort(niz, n, sizeof(double), compare_acs); 
    else if(strcmp(argv[1], "-qsortr")==0)
      qsort(niz, n, sizeof(double), compare_desc);    

    printf("\n--------------------------------\n");
    printf("Ispisujemo elemente nakon modifikacije!\n"); 
    print_elements(niz, n);

    free(niz);  

    return 0;
}
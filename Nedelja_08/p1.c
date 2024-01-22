#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void greska(){
    fprintf(stderr,"-1\n");
    exit(EXIT_FAILURE);
}

void swap(int *niz, int p, int q){
    int tmp=niz[p];
    niz[p]=niz[q];
    niz[q]=tmp;
}

void bubble_sort(int *niz, int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(niz[j]>niz[j+1])
              swap(niz, j, j+1);
        }
    }
}

void merge_sort(int *niz, int l , int r, int *help){
    if(l>=r)
      return;

    int s=l+(r-l)/2;  
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

void quick_sort(int *niz, int l, int r){
    if(l>=r)
      return;

    int pivot_position=l;
    for(int i=l+1;i<=r;i++){
       if(niz[i] < niz[l])
         swap(niz, i, ++pivot_position); 
    }

    swap(niz, l, pivot_position);
    
    quick_sort(niz, l, pivot_position-1);
    quick_sort(niz, pivot_position+1, r);  
}

void print_elements(int *niz, int n){
    for(int i=0;i<n;i++){
        printf("%d ", niz[i]);
    }
    printf("\n");
}

void selection_sort(int* niz, int n){
    for(int i=0;i<n;i++){
        int min_position=i;
        for(int j=i+1;j<n;j++){
            if(niz[j]<niz[min_position])
              min_position=j;
        }
        
        int tmp=niz[i];
        niz[i]=niz[min_position];
        niz[min_position]=tmp;
    }
}

void selection_sort_reverse(int* niz, int n){
    for(int i=0;i<n;i++){
        int max_position=i;
        for(int j=i+1;j<n;j++){
            if(niz[j]>niz[max_position])
              max_position=j;
        }
        
        int tmp=niz[i];
        niz[i]=niz[max_position];
        niz[max_position]=tmp;
    }
}

void insertion_sort(int *niz, int n){
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

void insertion_sort_reverse(int *niz, int n){
    int i;
    int j;
    for(i=1;i<n;i++){
        int current=niz[i];
        for(j=i; j>0 && current>niz[j-1];j--){
            niz[j]=niz[j-1];
        }
        niz[j]=current;
    }
}

int compare(const void *x, const void *y){
    return *(int*)x-*(int*)y;
}

int main(int argc, char* argv[]){

    if(argc!=2){
        greska();
    }

    int n;
    int *niz;
    printf("Unesite dimenziju niza: \n");
    scanf("%d", &n);
    if(n<=0)
      greska();

    niz=(int*)malloc(n*sizeof(int));
    if(niz==NULL)
      greska();

    printf("Unesite elemente niza: \n");
    for(int i=0;i<n;i++){
        scanf("%d", &niz[i]);
    }

    int *help=(int*)malloc(n*sizeof(int));
    if(help==NULL)
      greska();

    if(strcmp(argv[1], "-s")==0)
      selection_sort(niz, n);
    else if(strcmp(argv[1], "-sr")==0)
      selection_sort_reverse(niz, n);
    else if(strcmp(argv[1], "-i")==0)
      insertion_sort(niz, n);
    else if(strcmp(argv[1], "-ir")==0)
      insertion_sort_reverse(niz, n);
    else if(strcmp(argv[1], "-b")==0)
      bubble_sort(niz, n);
    else if(strcmp(argv[1], "-m")==0)
      merge_sort(niz, 0, n-1, help);
    else if(strcmp(argv[1], "-q")==0)
      quick_sort(niz, 0, n-1);
    else if(strcmp(argv[1], "-qsort")==0)
      qsort(niz, n, sizeof(int), compare);
    else    
      greska();          
    
    printf("Elementi su uspesno ucitani!\n");
    printf("Niz nakon modifikacije izgleda ovako: \n");
    print_elements(niz, n);
    printf("\n------------------------------\n");

    free(niz);    

    return 0;
}
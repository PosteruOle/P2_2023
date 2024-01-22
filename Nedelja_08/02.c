#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX 51

void greska(){
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

void print_elements(char** niz, int n){
     for(int i=0;i<n;i++){
        printf("%s ", niz[i]);
     }
     printf("\n");
}

void insertion_sort(char** niz, int n){
    int i;
    int j;
    for(i=1;i<n;i++){
        char current[MAX];
        strcpy(current, niz[i]);
        for(j=i;j>0 && strcmp(niz[j-1], current)>0; j--)
           strcpy(niz[j], niz[j-1]);

        strcpy(niz[j], current);   
    }
}

void insertion_sort_reverse(char** niz, int n){
    int i;
    int j;
    for(i=1;i<n;i++){
        char current[MAX];
        strcpy(current, niz[i]);
        for(j=i;j>0 && strcmp(niz[j-1], current)<=0; j--)
           strcpy(niz[j], niz[j-1]);

        strcpy(niz[j], current);   
    }
    
}

void selection_sort(char** niz, int n){
    for(int i=0;i<n;i++){
        int min_index=i;
        for(int j=i+1;j<n;j++){
           if(strcmp(niz[j], niz[min_index])<0)
             min_index=j;
        }

        char tmp[MAX];
        strcpy(tmp, niz[i]);
        strcpy(niz[i], niz[min_index]);
        strcpy(niz[min_index], tmp);
    }
}

void selection_sort_reverse(char** niz, int n){
    for(int i=0;i<n;i++){
        int min_index=i;
        for(int j=i+1;j<n;j++){
           if(strcmp(niz[j], niz[min_index])>=0)
             min_index=j;
        }

        char tmp[MAX];
        strcpy(tmp, niz[i]);
        strcpy(niz[i], niz[min_index]);
        strcpy(niz[min_index], tmp);
    }
}



int main(int argc, char *argv[]){

    if(argc!=2)
      greska();

    int n;
    char **niz;

    printf("Unesite dimenziju niza: \n");
    scanf("%d", &n);  
    
    niz=(char**)malloc(n*sizeof(char*));
    if(niz==NULL)
      greska();

    printf("Unesite elemente niza: \n"); 
    for(int i=0;i<n;i++){
        niz[i]=(char*)malloc(MAX*sizeof(char));
        if(niz[i]==NULL)
          greska();
        scanf("%s", niz[i]);  
    }
    printf("Elementi su uspesno uneti!\n");
    printf("\n-----------------------------------\n");


    if(strcmp(argv[1], "-i")==0)
      insertion_sort(niz, n);
    else if(strcmp(argv[1], "-ir")==0)
      insertion_sort_reverse(niz, n);
    else if(strcmp(argv[1], "-s")==0)
      selection_sort(niz, n);
    else if(strcmp(argv[1], "-sr")==0)
      selection_sort_reverse(niz, n);
    else 
      greska();      

    printf("\n-----------------------------------\n");
    printf("Niz nakon primene zadatog algoritma sortiranja izgleda ovako: \n");
    print_elements(niz, n);
    printf("\n-----------------------------------\n");


    for(int i=0;i<n;i++)
       free(niz[i]);
    free(niz);   

    return 0;
}
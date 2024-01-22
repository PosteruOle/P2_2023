#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void greska(){
    fprintf(stderr,"-1\n");
    exit(EXIT_FAILURE);
}

typedef struct Cvor{
  char c;
  struct Cvor *sledeci;
} Cvor;

Cvor *napravi_cvor(char c){
    Cvor *tmp=malloc(sizeof(Cvor));
    if(tmp==NULL)
      greska();
    tmp->c=c;
    tmp->sledeci=NULL;
    return tmp;  
}

void dodaj_na_kraj(Cvor **glava, int c){
    if(*glava==NULL){
        *glava=napravi_cvor(c);
        return;
    }
    Cvor *tmp=*glava;
    while(tmp->sledeci!=NULL){
        tmp=tmp->sledeci;
    }
    tmp->sledeci=napravi_cvor(c);
}

void ispisi_listu(Cvor *glava){
    if(glava==NULL)
      return;
    if(glava->sledeci==NULL){
      printf("%c \n", glava->c);
      return;  
    }  

    printf("%c -> ", glava->c);
    ispisi_listu(glava->sledeci);
}

int check(Cvor **glava, char c){
    if(*glava==NULL)
      return 1;
    if((*glava)->sledeci==NULL){
        if((*glava)->c)
    }  
    Cvor *tmp=*glava;
    while(tmp->sledeci!=NULL){
        tmp=tmp->sledeci;
    }
}

int main(){
 
    Cvor *glava=NULL;
    char c;
    int flag=1;
    while(1){
        scanf("%c ", &c);
        if(c=='0')
          break;
        if(c==')' || c==']' || c=='}'){
          if(check(&glava, c)==1){
            flag=0;
            break;
          }
        }  
        if(c=='{' || c=='(' || c=='[')
          dodaj_na_kraj(&glava, c);  
    }
    if(glava==NULL && flag)
      printf("Zagrade su pravilno uparene!\n");
    else 
      printf("Zagrade nisu pravilno uparene!\n");  
    //ispisi_listu(glava);

    return 0;
}
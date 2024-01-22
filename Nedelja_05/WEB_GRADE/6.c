/*
Napisati rekurzivnu funkciju int broj_pojavljivanja(char* s1, char* s2) koja prebrojava koliko puta se niska s1 javlja u okviru niske s2.
Napisati program koji testira napisanu funkciju. Sa standardnog ulaza se zadaju dve niske (maksimalne dužine 63 karaktera). Na standardni izlaz ispisati koliko puta se prva niska pojavljuje unutar druge niske.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 64

void greska(){
  fprintf(stderr, "-1\n");
  exit(EXIT_FAILURE);
}

int broj_pojavljivanja(char* s1, char* s2){
   if(s2[0]=='\0')
     return 0;
   
   if(strlen(s1)>strlen(s2))
     return 0;  
     
   int n=strlen(s1);
   if(strncmp(s1, s2, n)==0)
     return 1+broj_pojavljivanja(s1, s2+1);
   else
     return broj_pojavljivanja(s1, s2+1);    
}

int main(){

  char s1[MAX];
  char s2[MAX];
  scanf("%s %s", s1, s2);
  printf("%d\n", broj_pojavljivanja(s1, s2)); 
   
  return 0;
}

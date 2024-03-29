#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 64

void greska(){
  fprintf(stderr, "-1\n");
  exit(EXIT_FAILURE);
}

int poredi(char* s1, char* s2){
   if(s1[0]=='\0' && s2[0]=='\0')
     return 0;
   
   if(s1[0]=='\0' || s2[0]=='\0')
     return 1;
   
   if(s1[0]!=s2[0])
     return 1;
   
   return poredi(s1+1, s2+1);      
}

int main(){

 char s1[MAX];
 char s2[MAX];
 while(scanf("%s %s", s1, s2)!=EOF){
      printf("%d\n", poredi(s1, s2));
 }

 return 0;
}

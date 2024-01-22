#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 64

void greska(){
  fprintf(stderr,"-1\n");
  exit(EXIT_FAILURE);
}

char* sadrzi(char* s, char c){
   if(s[0]=='\0')
     return NULL;
   
   if(s[0]==c)
     return s;
   else
     return sadrzi(s+1, c);    
}

int main(){

 char niska[MAX];
 char c;
 scanf("%s %c", niska, &c);
 char *value=sadrzi(niska, c);
 if(value==NULL)
   printf("-1");
 else
   printf("%d", (int)(value-niska));  


 return 0;
}

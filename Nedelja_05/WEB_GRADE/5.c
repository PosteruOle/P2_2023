#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 64

void greska(){
  fprintf(stderr, "-1\n");
  exit(EXIT_FAILURE);
}

char* podniska(char* s1, char* s2){
  if(s2[0]=='\0')
    return NULL;
  int n=strlen(s1);
  if(strncmp(s1, s2, n)==0)
    return s2;
  else
    return podniska(s1, s2+1);    
}

int main(){
 
 //man strncmp
 char s1[MAX];
 char s2[MAX];
 scanf("%s %s", s1, s2);
 char *value=podniska(s1, s2);
 if(value==NULL)
   printf("-1\n");
 else  
   printf("%d", (int)(value-s2));

 return 0;
}

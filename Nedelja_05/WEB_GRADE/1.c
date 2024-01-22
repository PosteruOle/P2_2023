#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void greska(){
 fprintf(stderr,"-1");
 exit(EXIT_FAILURE);
}

int izbaci_parne(int x){
   if(x<=9 && x%2==0)
     return 0;
   if(x<=9)
     return x;
   if(x%10%2==0)
     return izbaci_parne(x/10);
   else 
     return izbaci_parne(x/10)*10+x%10;      
}

int main(int argc, char *argv[]){
 
 if(argc!=2)
   greska();
 
 int sign=1;
 int x=atoi(argv[1]);
 if(x<0){
   sign=-1;
   x=abs(x);
 }
 printf("%d", sign*izbaci_parne(x));

 return 0;
}

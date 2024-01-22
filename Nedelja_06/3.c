#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 11

void greska(){
  fprintf(stderr,"-1\n");
  exit(EXIT_FAILURE);
}

double sqr(double x){
  return x*x;
}

double limes(int n, double a, double (*f)(double)){
  return (*f)(a+1.0/n);
}

int main(){

 int n;
 double a;
 double (*f)(double);
 char funkcija[MAX];
 
 printf("Unesite ime funkcije, n i a: \n");
 scanf("%s %d %lf", funkcija, &n, &a);
 
 if(strcmp(funkcija, "sin")==0)
   f=sin;
 else if(strcmp(funkcija, "cos")==0)
   f=&cos;
 else if(strcmp(funkcija, "tan")==0)
   f=&tan;
 else if(strcmp(funkcija, "atan")==0)
   f=&atan;
 else if(strcmp(funkcija, "acos")==0)
   f=&acos;
 else if(strcmp(funkcija, "asin")==0)
   f=&asin;
 else if(strcmp(funkcija, "exp")==0)
   f=&exp;
 else if(strcmp(funkcija, "log")==0)
   f=&log;
 else if(strcmp(funkcija, "log10")==0)
   f=&log;
 else if(strcmp(funkcija, "sqrt")==0)
   f=&sqrt;
 else if(strcmp(funkcija, "sqr")==0)
   f=&sqr;
 else
   greska();
   
 printf("Limes funckije u tacki a iznosi: %.6lf.\n", limes(n, a, f));  
 
 
 
 return 0;
}

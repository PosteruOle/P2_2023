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

double integral(int n, double a, double b,  double (*f)(double)){
  double h=(b-a)/n;
  double suma=0;
  for(int i=1;i<=n;i++){
     suma+=f(a+i*h);
  }
  
  return h*((f(a)+f(b))/2+suma);
}

int main(){

 int n;
 double a;
 double b;
 double (*f)(double);
 char funkcija[MAX];
 
 printf("Unesite ime funkcije, n,  a, b: \n");
 scanf("%s %d %lf %lf", funkcija, &n, &a, &b);
 
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
   
 printf("Integral funckija na intervalu [a, b] iznosi: %.6lf.\n", integral(n, a, b, f));  
 
 
 
 return 0;
}


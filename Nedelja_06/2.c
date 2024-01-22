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

void tabela(int n, double a, double b, double (*f)(double)){
  double h=(b-a)/(n-1);
  printf("\n------------------------\n");
  for(int i=0;i<n;i++){
     printf("| %7.6lf | %7.6lf |\n", a+i*h,f(a+i*h));
  }
  
  printf("\n------------------------\n");
}


int main(int argc, char *argv[]){

 if(argc!=2)
   greska();
 
 int n;
 double a;
 double b;
 double (*f)(double);
 char funkcija[MAX];  
 strcpy(funkcija, argv[1]);
 
 printf("Unesite broj tacaka: \n");
 scanf("%d", &n);
 if(n<2)
   greska();
 
 printf("Unesite levu i desnu granicu intervala: \n");
 scanf("%lf %lf", &a, &b);
 if(a>=b)
   greska();  
 
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
   
 tabela(n, a, b, f);                        


 return 0;
}

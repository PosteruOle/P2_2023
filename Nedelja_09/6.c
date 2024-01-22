/*
Zadatak 6: Napisati funkciju unsigned set_bits(unsigned x, int p, int n, unsigned y) koja vraca
modifikovano x tako sto mu je izmenjeno n bitova pocevsi od pozicije p i na ta mesta je upisano poslednjih
n bitova broja y. Testirati funkciju pozivom u main-u, pri cemu se brojevi x, y, p i n unose sa standarnog
ulaza. Proveriti da li su brojevi p i p + n u odgovaraju cem opsegu i ispisati poruku o gresci ako nisu. Na
standarni izlaz ispisati bitove unesenog broja x i y i bitove novodobijenog broja.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void greska(){
    fprintf(stderr,"-1\n");
    exit(EXIT_FAILURE);
}

void print_bits(int x){
    unsigned mask=1;
    mask<<=sizeof(int)*8-1;
    //printf("\n--------------------\n");
    for(int i=1;i<=sizeof(int)*8;i++){
        if((mask & x)!=0)
          printf("1");
        else 
          printf("0");
        mask>>=1;    
    }
    printf("\n");
    //printf("\n--------------------\n");
}

unsigned set_bits(unsigned x, int p, int n, unsigned y){
   unsigned mask=~0;
   mask<<=n;
   mask=~mask;
   // mask = 000000...111111
   unsigned last_n=y & mask;
   mask<<=p;
   //mask = 000..001111..110000
   mask=~mask;
   x= x & mask;
   
   last_n<<=p;
   x|=last_n;
   
   return x;
}

int main(){

    unsigned x;
    unsigned y;
    int p;
    int n;
    printf("Unesite redom brojeve x i y: \n");
    scanf("%u %u", &x, &y);
    printf("Unesite redom brojeve p i n: \n");
    scanf("%d %d", &p, &n);
    printf("x: ");
    print_bits(x);
    
    printf("y: "); 
    print_bits(y);

    unsigned f=set_bits(x, p, n, y);
    printf("f: "); 
    print_bits(f);
    
    return 0;
}

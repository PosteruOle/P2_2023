#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned invert_k(unsigned x, int k){
    if(k<0 || k>=32){
      return x;
    }  
    if(k==0){
      return x^1;
    }
    unsigned mask=1;
    for(int i=0;i<32;i++){
       if(i%k==0){
         x^=mask; 
       }
       mask<<=1;
    }
    return x;  
}

void print_bits(unsigned x){
    unsigned mask=1;
    mask<<=sizeof(unsigned)*8-1;
    for(int i=1;i<=32;i++){
        if((mask & x)!=0)
          printf("1");
        else
          printf("0");
        mask>>=1;    
    }
    printf("\n");
}

int main(){

    int k;
    unsigned x;
    scanf("%d", &k);
    scanf("%u", &x);
    //print_bits(x);
    x=invert_k(x, k);
    //printf("\n---------------------------------\n");
    //print_bits(x);
    printf("%u", x);

    return 0;
}
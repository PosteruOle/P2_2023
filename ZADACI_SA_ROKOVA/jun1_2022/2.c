#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned k_jedinica(unsigned x, unsigned k){
   unsigned count=0;
   unsigned mask=~(~0<<k);
   for(int i=1;i<=sizeof(int)*8-k+1;i++){
      if((x & mask)==mask)
        count++;
      mask<<=1;  
   }
   return count;
}

int main(){

    unsigned x;
    unsigned k;
    scanf("%u %u", &x, &k);
    printf("%u\n", k_jedinica(x, k));

    return 0;
}
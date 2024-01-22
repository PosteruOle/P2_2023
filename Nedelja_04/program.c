#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void greska(){
   fprintf(stderr, "-1\n");
   exit(EXIT_FAILURE);
}

int main(){

    printf("Hello world!\n");

    return 0;
}
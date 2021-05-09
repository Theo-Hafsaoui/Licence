#include <gmp.h>
#include <stdio.h>
int main( ) 
{ 
  
    int n,i;
    n=0;
    i=1;
    FILE *fileNE ; 
    char c[50];
    fileNE = fopen("test.txt", "r") ; 
    if ( fileNE == NULL ) 
    { 
        printf( "no such file,find. awkward..." ) ; 
    } 
    else
    { 

        while( fgets ( c, 50, fileNE ) != NULL ) 
        { 
            n=(int)'c';
            printf( "%c" , c ) ; 
            i*=100; 
         } 
        fclose(fileNE) ; 
        printf("val=%d",n); 
    } 
    return 0;         
} 
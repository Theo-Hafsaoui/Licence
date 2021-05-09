#include <gmp.h>
#include <stdio.h>


int main(){
    int c;
    FILE *fp = fopen("test.txt", "r");

    if (fp == NULL)
    {
    printf("Error opening file!\n");
    return -1;
    }

    while ((c = fgetc(fp)) != EOF)
    {
        printf("%d",c);
    }

    fclose(fp);
}

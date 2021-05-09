#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

typedef enum {False=0,True} tbool;

tbool Palin(char * ch){
    int len;len = strlen(ch);
    int i=0;
    while ((i<len/2)&&(ch[i]==ch[len-(i+1)]))
    {
        i++;
    }
    if (i==len/2)
    {
        return True;
    }
    else
    {
        return False;
    }
     
}

int main(){
    char ch[50];
    printf ("Mot a tester : ");
    scanf("%s", ch);
    tbool v = Palin(ch);
    if (v== False)
    {
        printf("Non");
    }
    else
    {
        printf("oui");
    }
    

    
}

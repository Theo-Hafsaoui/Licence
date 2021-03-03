#include <stdio.h>

int main(){

    char ch1[5];
    printf("Enter  word :");
    scanf ("%s",&ch1);
    for (int i = 1; i < (5/2); i++)
    {
        if (ch1[i]!=ch1[5-i]){
            printf("pas palindrome");
            return NULL;
        }
    }
    printf("est un palindrome");


}